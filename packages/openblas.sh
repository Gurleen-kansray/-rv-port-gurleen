#!/bin/bash
# Build OpenBLAS for RISC-V
cd /mnt/d/rv-port-work/-rv-port-gurleen
PKG_NAME="openblas"
VERSION="0.3.33"

echo "Building $PKG_NAME-$VERSION for riscv64"

# Clone if not exists
if [ ! -d "build-riscv64/$PKG_NAME" ]; then
    git clone --depth 1 --branch v$VERSION https://github.com/OpenMathLib/OpenBLAS.git build-riscv64/$PKG_NAME
fi

cd build-riscv64/$PKG_NAME

# Cross-compile for RISC-V
make TARGET=RISCV64_GENERIC CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran \
     CROSS=1 CROSS_SUFFIX=riscv64-linux-gnu- NO_LAPACK=0

# Install to temporary directory
make install DESTDIR=/tmp/${PKG_NAME}-install

# Create .deb
/mnt/d/rv-port-work/-rv-port-gurleen/scripts/create-deb.sh $PKG_NAME $VERSION /tmp/${PKG_NAME}-install

echo "✅ $PKG_NAME build complete"
