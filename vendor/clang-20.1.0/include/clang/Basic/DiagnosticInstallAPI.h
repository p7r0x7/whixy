//===--- DiagnosticInstallAPI.h - Diagnostics for InstallAPI-----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_BASIC_DIAGNOSTICINSTALLAPI_H
#define LLVM_CLANG_BASIC_DIAGNOSTICINSTALLAPI_H

#include "clang/Basic/Diagnostic.h"
namespace clang {
namespace diag {
enum {
#define DIAG(ENUM, FLAGS, DEFAULT_MAPPING, DESC, GROUP, SFINAE, NOWERROR,      \
             SHOWINSYSHEADER, SHOWINSYSMACRO, DEFERRABLE, CATEGORY)            \
  ENUM,
#define INSTALLAPISTART
#include "clang/Basic/DiagnosticInstallAPIKinds.inc"
#undef DIAG
  NUM_BUILTIN_INSTALLAPI_DIAGNOSTICS
};

#define DIAG_ENUM(ENUM_NAME)                                                   \
  namespace ENUM_NAME {                                                        \
  enum {
#define DIAG_ENUM_ITEM(IDX, NAME) NAME = IDX,
#define DIAG_ENUM_END()                                                        \
  }                                                                            \
  ;                                                                            \
  }
#include "clang/Basic/DiagnosticInstallAPIEnums.inc"
#undef DIAG_ENUM_END
#undef DIAG_ENUM_ITEM
#undef DIAG_ENUM
} // namespace diag
} // namespace clang
#endif // LLVM_CLANG_BASIC_DIAGNOSTICINSTALLAPI_H
