#!/bin/bash
# Package stream-rvv 5.10 as riscv64 .deb
PKG_DIR=/tmp/stream-rvv-deb
mkdir -p $PKG_DIR/usr/local/bin $PKG_DIR/DEBIAN
cat > $PKG_DIR/DEBIAN/control << CTRL
Package: stream-rvv-riscv64
Version: 5.10
Architecture: riscv64
Maintainer: Gurleen Kansray <gurleen72542@gmail.com>
Description: stream-rvv 5.10 cross-compiled for riscv64
CTRL
dpkg-deb --build $PKG_DIR /home/acer/-rv-port-gurleen/debs/stream-rvv_5.10_riscv64.deb
