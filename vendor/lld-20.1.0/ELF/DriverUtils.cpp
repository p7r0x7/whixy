//===- DriverUtils.cpp ----------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains utility functions for the ctx.driver. Because there
// are so many small functions, we created this separate file to make
// Driver.cpp less cluttered.
//
//===----------------------------------------------------------------------===//

#include "Config.h"
#include "Driver.h"
#include "lld/Common/CommonLinkerContext.h"
#include "lld/Common/Reproduce.h"
#include "llvm/Option/Option.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/TimeProfiler.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/TargetParser/Triple.h"
#include <optional>

using namespace llvm;
using namespace llvm::sys;
using namespace llvm::opt;
using namespace lld;
using namespace lld::elf;

// Create OptTable

#define OPTTABLE_STR_TABLE_CODE
#include "Options.inc"
#undef OPTTABLE_STR_TABLE_CODE

// Create prefix string literals used in Options.td
#define OPTTABLE_PREFIXES_TABLE_CODE
#include "Options.inc"
#undef OPTTABLE_PREFIXES_TABLE_CODE

// Create table mapping all options defined in Options.td
static constexpr opt::OptTable::Info optInfo[] = {
#define OPTION(...) LLVM_CONSTRUCT_OPT_INFO(__VA_ARGS__),
#include "Options.inc"
#undef OPTION
};

ELFOptTable::ELFOptTable()
    : GenericOptTable(OptionStrTable, OptionPrefixesTable, optInfo) {}

// Set color diagnostics according to --color-diagnostics={auto,always,never}
// or --no-color-diagnostics flags.
static void handleColorDiagnostics(Ctx &ctx, opt::InputArgList &args) {
  auto *arg = args.getLastArg(OPT_color_diagnostics);
  if (!arg)
    return;
  StringRef s = arg->getValue();
  if (s == "always")
    ctx.e.errs().enable_colors(true);
  else if (s == "never")
    ctx.e.errs().enable_colors(false);
  else if (s != "auto")
    ErrAlways(ctx) << "unknown option: --color-diagnostics=" << s;
}

static cl::TokenizerCallback getQuotingStyle(Ctx &ctx,
                                             opt::InputArgList &args) {
  if (auto *arg = args.getLastArg(OPT_rsp_quoting)) {
    StringRef s = arg->getValue();
    if (s != "windows" && s != "posix")
      ErrAlways(ctx) << "invalid response file quoting: " << s;
    if (s == "windows")
      return cl::TokenizeWindowsCommandLine;
    return cl::TokenizeGNUCommandLine;
  }
  if (Triple(sys::getProcessTriple()).isOSWindows())
    return cl::TokenizeWindowsCommandLine;
  return cl::TokenizeGNUCommandLine;
}

// Gold LTO plugin takes a `--plugin-opt foo=bar` option as an alias for
// `--plugin-opt=foo=bar`. We want to handle `--plugin-opt=foo=` as an
// option name and `bar` as a value. Unfortunately, OptParser cannot
// handle an option with a space in it.
//
// In this function, we concatenate command line arguments so that
// `--plugin-opt <foo>` is converted to `--plugin-opt=<foo>`. This is a
// bit hacky, but looks like it is still better than handling --plugin-opt
// options by hand.
static void concatLTOPluginOptions(Ctx &ctx,
                                   SmallVectorImpl<const char *> &args) {
  SmallVector<const char *, 256> v;
  for (size_t i = 0, e = args.size(); i != e; ++i) {
    StringRef s = args[i];
    if ((s == "-plugin-opt" || s == "--plugin-opt") && i + 1 != e) {
      v.push_back(ctx.saver.save(s + "=" + args[i + 1]).data());
      ++i;
    } else {
      v.push_back(args[i]);
    }
  }
  args = std::move(v);
}

// Parses a given list of options.
opt::InputArgList ELFOptTable::parse(Ctx &ctx, ArrayRef<const char *> argv) {
  // Make InputArgList from string vectors.
  unsigned missingIndex;
  unsigned missingCount;
  SmallVector<const char *, 256> vec(argv.data(), argv.data() + argv.size());

  // We need to get the quoting style for response files before parsing all
  // options so we parse here before and ignore all the options but
  // --rsp-quoting.
  opt::InputArgList args = this->ParseArgs(vec, missingIndex, missingCount);

  // Expand response files (arguments in the form of @<filename>)
  // and then parse the argument again.
  cl::ExpandResponseFiles(ctx.saver, getQuotingStyle(ctx, args), vec);
  concatLTOPluginOptions(ctx, vec);
  args = this->ParseArgs(vec, missingIndex, missingCount);

  handleColorDiagnostics(ctx, args);
  if (missingCount)
    ErrAlways(ctx) << args.getArgString(missingIndex) << ": missing argument";

  for (opt::Arg *arg : args.filtered(OPT_UNKNOWN)) {
    std::string nearest;
    if (findNearest(arg->getAsString(args), nearest) > 1)
      ErrAlways(ctx) << "unknown argument '" << arg->getAsString(args) << "'";
    else
      ErrAlways(ctx) << "unknown argument '" << arg->getAsString(args)
                     << "', did you mean '" << nearest << "'";
  }
  return args;
}

void elf::printHelp(Ctx &ctx) {
  auto &outs = ctx.e.outs();
  ELFOptTable().printHelp(
      outs, (ctx.arg.progName + " [options] file...").str().c_str(), "lld",
      false /*ShowHidden*/, true /*ShowAllAliases*/);
  outs << "\n";

  // Scripts generated by Libtool versions up to 2021-10 expect /: supported
  // targets:.* elf/ in a message for the --help option. If it doesn't match,
  // the scripts assume that the linker doesn't support very basic features
  // such as shared libraries. Therefore, we need to print out at least "elf".
  outs << ctx.arg.progName << ": supported targets: elf\n";
}

static std::string rewritePath(StringRef s) {
  if (fs::exists(s))
    return relativeToRoot(s);
  return std::string(s);
}

// Reconstructs command line arguments so that so that you can re-run
// the same command with the same inputs. This is for --reproduce.
std::string elf::createResponseFile(const opt::InputArgList &args) {
  SmallString<0> data;
  raw_svector_ostream os(data);
  os << "--chroot .\n";

  // Copy the command line to the output while rewriting paths.
  for (auto *arg : args) {
    switch (arg->getOption().getID()) {
    case OPT_reproduce:
      break;
    case OPT_INPUT:
      os << quote(rewritePath(arg->getValue())) << "\n";
      break;
    case OPT_o:
    case OPT_Map:
    case OPT_dependency_file:
    case OPT_print_archive_stats:
    case OPT_why_extract:
      // If an output path contains directories, "lld @response.txt" will
      // likely fail because the archive we are creating doesn't contain empty
      // directories for the output path (-o doesn't create directories).
      // Strip directories to prevent the issue.
      os << arg->getSpelling();
      if (arg->getOption().getRenderStyle() == opt::Option::RenderSeparateStyle)
        os << ' ';
      os << quote(path::filename(arg->getValue())) << '\n';
      break;
    case OPT_lto_sample_profile:
      os << arg->getSpelling() << quote(rewritePath(arg->getValue())) << "\n";
      break;
    case OPT_call_graph_ordering_file:
    case OPT_default_script:
    case OPT_dynamic_list:
    case OPT_export_dynamic_symbol_list:
    case OPT_just_symbols:
    case OPT_library_path:
    case OPT_remap_inputs_file:
    case OPT_retain_symbols_file:
    case OPT_rpath:
    case OPT_script:
    case OPT_symbol_ordering_file:
    case OPT_sysroot:
    case OPT_version_script:
      os << arg->getSpelling() << " " << quote(rewritePath(arg->getValue()))
         << "\n";
      break;
    default:
      os << toString(*arg) << "\n";
    }
  }
  return std::string(data);
}

// Find a file by concatenating given paths. If a resulting path
// starts with "=", the character is replaced with a --sysroot value.
static std::optional<std::string> findFile(Ctx &ctx, StringRef path1,
                                           const Twine &path2) {
  SmallString<128> s;
  if (path1.starts_with("="))
    path::append(s, ctx.arg.sysroot, path1.substr(1), path2);
  else
    path::append(s, path1, path2);

  if (fs::exists(s))
    return std::string(s);
  return std::nullopt;
}

std::optional<std::string> elf::findFromSearchPaths(Ctx &ctx, StringRef path) {
  for (StringRef dir : ctx.arg.searchPaths)
    if (std::optional<std::string> s = findFile(ctx, dir, path))
      return s;
  return std::nullopt;
}

// This is for -l<basename>. We'll look for lib<basename>.so or lib<basename>.a from
// search paths.
std::optional<std::string> elf::searchLibraryBaseName(Ctx &ctx,
                                                      StringRef name) {
  for (StringRef dir : ctx.arg.searchPaths) {
    if (!ctx.arg.isStatic)
      if (std::optional<std::string> s =
              findFile(ctx, dir, "lib" + name + ".so"))
        return s;
    if (std::optional<std::string> s = findFile(ctx, dir, "lib" + name + ".a"))
      return s;
  }
  return std::nullopt;
}

// This is for -l<namespec>.
std::optional<std::string> elf::searchLibrary(Ctx &ctx, StringRef name) {
  llvm::TimeTraceScope timeScope("Locate library", name);
  if (name.starts_with(":"))
    return findFromSearchPaths(ctx, name.substr(1));
  return searchLibraryBaseName(ctx, name);
}

// If a linker/version script doesn't exist in the current directory, we also
// look for the script in the '-L' search paths. This matches the behaviour of
// '-T', --version-script=, and linker script INPUT() command in ld.bfd.
std::optional<std::string> elf::searchScript(Ctx &ctx, StringRef name) {
  if (fs::exists(name))
    return name.str();
  return findFromSearchPaths(ctx, name);
}
