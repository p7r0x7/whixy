#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -eu; umask 0022

cd src; rm -rf antlr; install -dm 0755 antlr ../.build

jar --no-compress --date 1980-01-01T00:00:02Z --main-class org.antlr.v4.Tool \
	--create --file "../.build/antlr.jar" -C ../vendor/antlr-4* .

java -jar ../.build/antlr.jar \
    -Dlanguage=Cpp -visitor -no-listener -o antlr -package Whixy -encoding utf-8 WhixyParser.g4 WhixyLexer.g4 \
    || printf '\n\t\033[33mantlr4 failed to execute successfully: continuing...\033[0m\n\n'
rm antlr/*.interp antlr/*.tokens

find .. \( -path '../vendor' -o -name '.[!.]*' \) -prune -o ! -type d -name '*.zig' -exec zig fmt {} + -o \
    \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i --style='file:../.clang-format' {} +

git add .; git diff --stat HEAD; git reset >/dev/null