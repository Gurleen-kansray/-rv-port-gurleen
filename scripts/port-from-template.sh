#!/bin/bash
# port-from-template.sh — scaffold a new port directory
# Usage: ./port-from-template.sh --name <pkg> --version <ver>
set -e
NAME="" VERSION=""
while [[ $# -gt 0 ]]; do
    case $1 in
        --name) NAME=$2; shift 2;;
        --version) VERSION=$2; shift 2;;
        *) echo "Unknown arg: $1"; exit 1;;
    esac
done
if [ -z "$NAME" ] || [ -z "$VERSION" ]; then
    echo "Usage: $0 --name <pkg> --version <ver>"
    exit 1
fi

DIR="/home/acer/-rv-port-gurleen/ports/$NAME"
mkdir -p "$DIR"

cat > "$DIR/bootstrap.sh" << BOOTSTRAP
#!/bin/bash
# Clone and patch $NAME $VERSION
# wget https://example.com/$NAME-$VERSION.tar.gz
# tar xf $NAME-$VERSION.tar.gz
echo "TODO: clone/patch $NAME $VERSION"
BOOTSTRAP

cat > "$DIR/build.sh" << BUILD
#!/bin/bash
# Cross-compile $NAME for riscv64
# cmake -S . -B build-riscv64 -DCMAKE_TOOLCHAIN_FILE=/home/acer/-rv-port-gurleen/riscv64-toolchain.cmake
# make -C build-riscv64 -j\$(nproc)
echo "TODO: build $NAME"
BUILD

cat > "$DIR/verify.conf" << VERIFY
binary=
sentinel=
VERIFY

cat > "$DIR/package-deb.sh" << PACKAGE
#!/bin/bash
# Package $NAME $VERSION as riscv64 .deb
PKG_DIR=/tmp/${NAME}-deb
mkdir -p \$PKG_DIR/usr/local/bin \$PKG_DIR/DEBIAN
cat > \$PKG_DIR/DEBIAN/control << CTRL
Package: $NAME-riscv64
Version: $VERSION
Architecture: riscv64
Maintainer: Gurleen Kansray <gurleen72542@gmail.com>
Description: $NAME $VERSION cross-compiled for riscv64
CTRL
dpkg-deb --build \$PKG_DIR /home/acer/-rv-port-gurleen/debs/${NAME}_${VERSION}_riscv64.deb
PACKAGE

cat > "$DIR/smoke-test.sh" << SMOKE
#!/bin/bash
echo "TODO: smoke test for $NAME"
SMOKE

chmod +x "$DIR"/*.sh
echo "✅ Scaffolded: $DIR"
echo "Fill in: bootstrap.sh, build.sh, verify.conf, package-deb.sh"
