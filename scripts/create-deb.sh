#!/bin/bash
# Usage: ./scripts/create-deb.sh <package-name> <version> <install-path>

PKG_NAME=$1
PKG_VERSION=$2
INSTALL_PATH=$3
ARCH="riscv64"
MAINTAINER="Gurleen Kansray <gurleen72542@gmail.com>"

if [ -z "$PKG_NAME" ] || [ -z "$PKG_VERSION" ]; then
    echo "Usage: $0 <package-name> <version> [install-path]"
    exit 1
fi

DEB_ROOT="debs/${PKG_NAME}_${PKG_VERSION}_${ARCH}"
mkdir -p $DEB_ROOT/DEBIAN
mkdir -p $DEB_ROOT/usr/lib
mkdir -p $DEB_ROOT/usr/include
mkdir -p $DEB_ROOT/usr/bin

# Create control file
cat > $DEB_ROOT/DEBIAN/control << EOF
Package: $PKG_NAME
Version: $PKG_VERSION
Architecture: $ARCH
Maintainer: $MAINTAINER
Description: $PKG_NAME - riscv64 cross-compiled port
 Built and validated under qemu-riscv64-static.
