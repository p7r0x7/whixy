#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor/ must be kept current in VCS with this file that publicly defines its deterministic generation.
# And for security reasons, only @p7r0x7 may sign and push commits changing vendor.sh and vendor/.

curl() { command curl -sL "$@"; }
set -eu; umask 0022; srcs=/tmp/srcs;
install() { command install -dm 0755 "$@"; }
command -v 7z >/dev/null && dec() { 7z "$@"; }
command -v 7zz >/dev/null && dec() { 7zz "$@"; }
command -v gtar >/dev/null && tar() { gtar "$@"; }
clean() { [ $? = 0 ] || rm -rf "$pkg" "$srcs" & }
[ $# = 0 ] || return 0 # Sourcing mode ends here.

start()
{
	trap clean INT HUP TERM EXIT; . ../scripts/vendor.sh # Borrows $@
	name="$1"; pkg=/tmp/"$name"; rm -rf "$pkg"; install "$pkg"
}
get()
{
	hash="$1"; [ -f "$srcs/$base" ] || curl "$url" -o "$srcs/$base"
	actual="$(b3sum < "$srcs/$base")"; [ "$actual" = "$hash  -" ] \
		|| { printf '%s !=\n%s\n' "$hash" "${actual%  -}"; rm -rf "$srcs/$base" & return 1; }
}
finish()
{
	find "$pkg" \( -name '.[!.]*' -o -empty -o -iname '*changelog*' -o -iname '*bazel*' \) -exec rm -rf {} +
    for file in "$pkg"/*; do rm -rf "./${file##*/}"; done; mv "$pkg"/* .; rmdir "$pkg"
}

# Separate collections of parallelly-acquiesced dependencies.
llvm()
{
	start llvm; semv=20.1.2 base="llvm-project-$semv.src.tar.xz" deps="clang cmake compiler-rt lld llvm polly"
	url="https://github.com/llvm/llvm-project/releases/download/llvmorg-$semv/$base"
	(
		get 6054e9b0e1b1f991875a2361f80844f7b6ff6614f1352c0bb7a144cd43c2651b
		dec e -so "$srcs/$base" \
			| tar -xf - --strip-components=1 -C "$pkg" $(printf "llvm-project-$semv.src/%s\n" $deps)

		cd "$pkg"; for dep in $deps; do mv "$dep" "$dep-$semv"; done
		rm -rf -- */benchmark* llvm-*/bindings polly-*/lib/External/isl/test_inputs
		find . \( -type d -name examples -o -type d -name doc -o -type d -name docs -o -type d -name test \
			-o -type d -name tests -o -type d -name unittests -o -type d -name www \) -exec rm -rf {} +
	); finish
}
other()
{
	start other; semv=master base=LRSTAR-$semv.tar.gz url="https://github.com/p7r0x7/LRSTAR/archive/$semv.tar.gz"
	(
		get 50dc3a5c181655b7da2f6a7d232e081c8c8721524c11607fb1db24137857b0c1; install "$pkg/lrstar-$semv"
		dec e -so "$srcs/$base" | tar -xf - --strip-components=1 -C "$pkg/lrstar-$semv"

		cd "$pkg/lrstar-$semv"; rm -rf -- bin doc examples grammars */*.bat */*.html */workspace*
	) &

	semv=1.5.7 base="zstd-$semv.tar.zst" url="https://github.com/facebook/zstd/releases/download/v$semv/$base"
	(
		get 910e80e17ac5857f357f0beacc6554677ba5fceeada0e80089115058295deecc; install "$pkg/zstd-$semv"
		zstd -cd "$srcs/$base" | tar -xf - --strip-components=1 -C "$pkg/zstd-$semv"

		cd "$pkg/zstd-$semv"; rm -rf contrib build/meson build/VS* doc lib/legacy programs tests zlibWrapper
		find . \( -type d -name example -o -type d -name examples \) -exec rm -rf {} +
	) & wait; finish
}

install "$srcs" vendor; cd vendor; llvm & other & wait
