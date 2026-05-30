#!/bin/bash
# Single package builder with fallback strategies
# Usage: ./build_package.sh <name> <url>

set -e

PKG_NAME=$1
PKG_URL=$2
BUILD_DIR="/mnt/d/build_${PKG_NAME}"
LOG_FILE="/mnt/d/rv-port/automation/logs/${PKG_NAME}.log"

mkdir -p "$BUILD_DIR" "$(dirname "$LOG_FILE")"

echo "[$(date)] Building $PKG_NAME..." | tee -a "$LOG_FILE"

# Check if URL is valid
if [ -z "$PKG_URL" ]; then
    echo "ERROR: No URL provided for $PKG_NAME" | tee -a "$LOG_FILE"
    exit 1
fi

# Clone or download
cd "$BUILD_DIR"
if [[ "$PKG_URL" == *.git ]]; then
    git clone --depth 1 "$PKG_URL" src 2>&1 | tee -a "$LOG_FILE"
else
    wget -q "$PKG_URL" -O src.tar.gz 2>&1 | tee -a "$LOG_FILE"
    mkdir src && tar xzf src.tar.gz -C src --strip-components=1
fi

cd src

# Try CMake first
if [ -f CMakeLists.txt ]; then
    echo "Using CMake..." | tee -a "$LOG_FILE"
    mkdir -p build && cd build
    cmake -DCMAKE_TOOLCHAIN_FILE=/mnt/d/rv-port/riscv64-toolchain.cmake \
          -DCMAKE_BUILD_TYPE=Release .. 2>&1 | tee -a "$LOG_FILE"
    make -j4 2>&1 | tee -a "$LOG_FILE"

# Fallback to autotools
elif [ -f configure ]; then
    echo "Using Autotools..." | tee -a "$LOG_FILE"
    ./configure --host=riscv64-linux-gnu --prefix=/usr/local 2>&1 | tee -a "$LOG_FILE"
    make -j4 2>&1 | tee -a "$LOG_FILE"

# Fallback to plain make
elif [ -f Makefile ]; then
    echo "Using plain Make..." | tee -a "$LOG_FILE"
    make -j4 CC=riscv64-linux-gnu-gcc 2>&1 | tee -a "$LOG_FILE"

else
    echo "ERROR: No known build system found" | tee -a "$LOG_FILE"
    exit 1
fi

echo "[$(date)] Successfully built $PKG_NAME" | tee -a "$LOG_FILE"
exit 0
