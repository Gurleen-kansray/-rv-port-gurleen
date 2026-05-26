#!/bin/bash
# Single package builder with fallback strategies
# Usage: ./build_package.sh <name> <url>

set -e

PKG_NAME=$1
PKG_URL=$2
BUILD_DIR="/mnt/d/build_${PKG_NAME}"
LOG_FILE="automation/logs/${PKG_NAME}.log"

mkdir -p "$BUILD_DIR" "$(dirname "$LOG_FILE")"

echo "[$(date)] Building $PKG_NAME..." | tee -a "$LOG_FILE"

# Clone
cd "$BUILD_DIR"
git clone --depth 1 "$PKG_URL" src 2>&1 | tee -a "$LOG_FILE"
cd src

# Try CMake first
if [ -f CMakeLists.txt ]; then
    echo "Using CMake..." | tee -a "$LOG_FILE"
    mkdir -p build && cd build
    cmake -DCMAKE_TOOLCHAIN_FILE=/mnt/d/rv-port/riscv64-toolchain.cmake \
          -DCMAKE_BUILD_TYPE=Release .. 2>&1 | tee -a "$LOG_FILE" && \
    make -j4 2>&1 | tee -a "$LOG_FILE"
    
# Fallback to autotools
elif [ -f configure ]; then
    echo "Using autotools..." | tee -a "$LOG_FILE"
    CC=riscv64-linux-gnu-gcc ./configure --host=riscv64-linux-gnu 2>&1 | tee -a "$LOG_FILE" && \
    make -j4 2>&1 | tee -a "$LOG_FILE"
    
# Fallback to make
elif [ -f Makefile ]; then
    echo "Using make..." | tee -a "$LOG_FILE"
    CC=riscv64-linux-gnu-gcc make -j4 2>&1 | tee -a "$LOG_FILE"
fi

echo "✅ $PKG_NAME built successfully" | tee -a "$LOG_FILE"
