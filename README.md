# Language Specification Design Goals

* Name: Whixy, pronounced "WIK-see" or /wɪk.siː/; Source file extension: .wx; Governing implementation license: Apache-2.0

###### Features Conducive to Systems Programming

* Pure and impure codepaths are explicitly delineated in the syntax.
* Conditions for automatic laziness in an otherwise eager syntax.
* Value Dlarations are immutable by default, and passed routine parameters are always immutable.

###### Features Conducive to Scripting

* Type specification is only necessary when unambigious type inference doesn't provide the wanted result
* Zig-like manual memory management, comptime, error handling, namespacing, and deferred-statement scoping
* Parametric polymorphism in the form of generics; ad hoc polymorphism in some form
* Routines are first class objects and will be designed to be anonymous by default (instead of two routine syntaxes, named and unnamed, there will just be the unnamed syntax that is to be assigned an identifier for reuse... just like everything else)
* LET THERE BE POSITS via integer-based software emulation or native hardware instruction generation when available in LLVM

###### Implementation Consistency Guarantees

* Compilers must halt; interpreters are... permitted.
* Primitive integer operations must be constant-time.
* Type inference must follow the specified, halting algorithm.
* Comptime code execution including constant folding cannot be delayed until runtime.
* The syntax specifies which expressions the compiler is to treat as unsequenced and handle lazily.

# Governing Implementation Design Goals

##### Support Targets (unless I'm paid to work on this)

OSes: MacOS, Windows, Linux, and FreeBSD
ISAs: x86 (32 and 64), arm (16, 32, and 64), riscv (32 and 64)

### Compiler

|   Mode  |                              Tentative Implementation                              |
| :------ | :--------------------------------------------------------------------------------- |
| `jit`   | `$reqd -O1 $safety`                                                                |
| `debug` | `$reqd -O0 -g $safety`                                                             |
| `safe`  | `$reqd -O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine -fopenmp-simd $safety` |
| `fast`  | `$reqd -O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine -fopenmp-simd`         |
| `tiny`  | `$reqd -Oz`                                                                        |
|         | `safety = -DSAFETY -Wall -Wextra -Wno-cast-function-type-mismatch`                 |
|         | `reqd = -fwrapv -nostdlib -nostartfiles`                                           |

* LLVM-based code generation
* JiT'd comptime code generation and execution followed by JiT'd or AoT'd runtime code generation (and possible execution)
* rustc-level informative errors for compiler-driven development (faster, due to less strict and less complex semantics)
* native and LLVM IR stdlib with comprehensive support only for SotA or appropriately longstanding or ubiquitous software
* struct and literal deduplication
* per-comptime backwards jump limit default, possibly 2^16
* per-file node limit default, possibly 2^32

### Standard Library Structs

| source file sans extension |                          contents and priority =>                           |   |
| :------------------------- | :-------------------------------------------------------------------------- | - |
| `builtin/builtin`          | builtin intrinsics                                                          | 0 |
| `compressor/brotli`        | (E then D) Brotli compression format                                        |   |
| `compressor/bzip2`         | (D only)   Bzip2 compression format                                         |   |
| `compressor/flate`         | (E and D)  Deflate or Gzip or Zlib compression format                       |   |
| `compressor/lzma`          | (D only)   LZMA compression format                                          |   |
| `compressor/lzma2`         | (D only)   LZMA2 compression format                                         |   |
| `compressor/zstd`          | (E then D) Zstandard compression format                                     |   |
| `container/sevenz`         | (D only)   7-zip LZMA, LZMA2, or Deflate archive format                     |   |
| `container/tar`            | (E and D)  gnu, ustar, and pax tape archive format                          |   |
| `container/xz`             | (D only)   XZ LZMA or LZMA2 container format                                |   |
| `container/zip`            | (E and D)  Zip or Zip64 Deflate archive format                              |   |
| `cova/cova`                | commands, options, values, and arguments; a reprised cli library            |   |
| `encoding/base2`           | (E and D)  12.5% efficient binary ASCII                                     |   |
| `encoding/base8`           | (E and D)  ~33.3% efficient octal ASCII                                     |   |
| `encoding/base10`          | (E and D)  ~42% efficient decimal ASCII                                     |   |
| `encoding/base16`          | (E and D)  50% efficient uppercase or lowercase hexadecimal ASCII           |   |
| `encoding/base32`          | (E and D)  62.5% efficient uppercase or lowercase base32 ASCII              |   |
| `encoding/base64`          | (E and D)  75% efficient base64 ASCII                                       |   |
| `encoding/base85`          | (E and D)  80% efficient base85 or ascii85 or z85 ASCII                     |   |
| `encoding/base91`          | (E and D)  ~81-88% efficient basE91 or Base91 ASCII                         |   |
| `encoding/csv`             | (E and D)                                                                   |   |
| `encoding/cbor`            | (E and D)                                                                   |   |
| `encoding/json`            | (E and D)                                                                   |   |
| `encoding/pam`             | (E and D)  uncompressed binary or ASCII format geared towards image data    |   |
| `encoding/toml`            | (E and D)                                                                   |   |
| `encoding/utf-8`           | (E and D)  utf-8 unicode text encoding                                      |   |
| `encoding/wtf-16`          | (E and D)  wtf-16 unicode text encoding                                     |   |
| `fmt/fmt`                  | value formatting and writing                                                |   |
| `hw/cpu`                   | cpu and cpu feature detection                                               |   |
| `hw/gpu`                   | gpu and gpu feature detection                                               |   |
| `hw/disk`                  | disk and disk feature detection                                             |   |
| `io/io`                    | generic readers and writers                                                 |   |
| `io/reader`                | generic readers and writers                                                 |   |
| `io/writer`                | generic readers and writers                                                 |   |
| `math/math`                | higher-level mathematics library                                            |   |
| `math/big/big`             | arbitrary-precision arithmetic and bitwise operation library                |   |
| `math/big/int`             | arbitrary-precision integer arithmetic                                      |   |
| `math/big/posit`           | arbitrary-precision posit arithmetic                                        |   |
| `math/big/rational`        | arbitrary-precision rational arithmetic                                     |   |
| `mem/mem`                  | generic memory manipulation                                                 |   |
| `mem/heap`                 | generic memory allocation                                                   |   |
| `mem/heap/allocator`       | memory allocator mixin                                                      |   |
| `mem/heap/arenaalloc`      | allocator wrapper that disables all freeing until deinitialization          |   |
| `mem/heap/rpmalloc`        | reimplementation of https://github.com/mjansson/rpmalloc                    |   |
| `mem/heap/stackalloc`      | fixed-buffer allocator; may only free the most recent allocation            |   |
| `mem/heap/safealloc`       | allocator wrapper that safety checks and panics or warns                    |   |
| `mem/heap/failalloc`       | allocator wrapper that precisely, randomly, or catastrophically fails       |   |
| `mem/sort`                 | generic memory sorting                                                      |   |
| `mime/mime`                | filetype detection                                                          |   |
| `os/os`                    | higher-level operating system interaction                                   |   |
| `os/exec`                  | higher-level program execution                                              |   |
| `os/fs`                    | higher-level filesystem interaction                                         |   |
| `os/fs/path`               | filepath traversal and manipulation                                         |   |
| `os/posix`                 | low-level POSIX interaction                                                 | 1 |
| `os/syscall`               | low-level kernel interaction                                                | 0 |
| `regex/regex`              | custom regex engine                                                         | 4 |
| `runt/runt`                | whixy's minimal runtime                                                     | 0 |
| `runt/tracy`               | execution tracing                                                           |   |
| `sync/atomic`              | low-level atomic primitives                                                 | 1 |
| `sync/sched`               | scheduler mixin and default schedulers                                      | 3 |
| `sync/chan`                | channel mixin and default channels                                          | 1 |
| `sync/coroutine`           | userspace threads                                                           | 3 |
| `sync/future`              | future mixin                                                                | 1 |
| `sync/mutex`               | mutex mixin and (rw)mutexes                                                 | 1 |
| `sync/thread`              | thread mixin and posix threads                                              | 1 |
| `sync/waitgroup`           | waitgroups                                                                  | 1 |
| `time/time`                |                                                                             | 2 |
| `time/tz`                  |                                                                             | 2 |
| `unicode`                  | current unicode tables                                                      | 2 |

+ others I don't yet know the importance of in my limited experience as a programmer

## Notes

- goto is limited to intra-routine jumps
- type-punning via aliasing pointer casting is limited to types of the same size in memory
- slicewise operators are vectorized where possible and must occur between identically-shaped integer or float slices
- overflow checks are opt-out at the operation level and are inlined; some safety checks always occur at runtime, while others 
