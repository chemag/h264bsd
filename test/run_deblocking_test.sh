#!/bin/sh
set -eu

repo_dir=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
build_dir=$(mktemp -d "${TMPDIR:-/tmp}/h264bsd-deblocking-test.XXXXXX")
trap 'rm -rf "$build_dir"' EXIT HUP INT TERM

"${CC:-cc}" \
  -std=c99 \
  -Wall \
  -Wextra \
  -Werror \
  -fsanitize=undefined \
  -fno-sanitize-recover=undefined \
  -I"$repo_dir/src" \
  "$repo_dir/test/h264bsd_deblocking_test.c" \
  -o "$build_dir/h264bsd_deblocking_test"

"$build_dir/h264bsd_deblocking_test"
