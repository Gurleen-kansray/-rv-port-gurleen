#!/bin/bash
set -e
PROJECT_DIR=$1
shift
SCRIPT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$PROJECT_DIR"
mkdir -p build-riscv && cd build-riscv
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE="$SCRIPT_DIR/riscv64-toolchain.cmake" \
  "$@"
make -j$(nproc)
