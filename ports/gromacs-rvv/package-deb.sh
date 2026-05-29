#!/bin/bash
# Package gromacs-rvv 2024.1 as riscv64 .deb
PKG_DIR=/tmp/gromacs-rvv-deb
mkdir -p $PKG_DIR/usr/local/bin $PKG_DIR/DEBIAN
cat > $PKG_DIR/DEBIAN/control << CTRL
Package: gromacs-rvv-riscv64
Version: 2024.1
Architecture: riscv64
Maintainer: Gurleen Kansray <gurleen72542@gmail.com>
Description: gromacs-rvv 2024.1 cross-compiled for riscv64
CTRL
dpkg-deb --build $PKG_DIR /home/acer/-rv-port-gurleen/debs/gromacs-rvv_2024.1_riscv64.deb
