#!/bin/bash
# universal-builder.sh - Build any package from database
# Usage: ./scripts/universal-builder.sh <package-name>

set -e

cd /mnt/d/rv-port-work/-rv-port-gurleen
PKG_NAME=$1
WORK_DIR="/tmp/build-${PKG_NAME}"
INSTALL_DIR="/tmp/${PKG_NAME}-install"

# Find package in database
LINE=$(grep "^${PKG_NAME}," packages/database.csv | head -1)
if [ -z "$LINE" ]; then
    echo "❌ Package $PKG_NAME not found in database"
    exit 1
fi

GIT_URL=$(echo $LINE | cut -d',' -f2)
BRANCH=$(echo $LINE | cut -d',' -f3)
BUILD_SYS=$(echo $LINE | cut -d',' -f4)

echo "=== Building $PKG_NAME ($BUILD_SYS) ==="

# Clean previous
rm -rf $WORK_DIR $INSTALL_DIR

# Clone
echo "[1/6] Cloning $GIT_URL (branch $BRANCH)..."
git clone --depth 1 --branch $BRANCH $GIT_URL $WORK_DIR

cd $WORK_DIR

# Build based on system
case $BUILD_SYS in
    cmake)
        echo "[2/6] Configuring with CMake..."
        cmake -B build -DCMAKE_TOOLCHAIN_FILE=/mnt/d/rv-port-work/-rv-port-gurleen/riscv64-linux-gnu.cmake \
              -DCMAKE_INSTALL_PREFIX=/usr -DBUILD_SHARED_LIBS=ON
        echo "[3/6] Building..."
        cmake --build build -j4
        echo "[4/6] Installing..."
        cmake --install build --prefix $INSTALL_DIR/usr
        ;;
    configure)
        echo "[2/6] Configuring with autotools..."
        # Update config.sub if needed
        if [ -f "build-aux/config.sub" ]; then
            cp /mnt/d/rv-port-work/-rv-port-gurleen/scripts/config.sub build-aux/config.sub 2>/dev/null || true
        fi
        ./configure --host=riscv64-linux-gnu --prefix=/usr
        echo "[3/6] Building..."
        make -j4
        echo "[4/6] Installing..."
        make install DESTDIR=$INSTALL_DIR
        ;;
    make)
        echo "[2/6] Building with make..."
        make CC=riscv64-linux-gnu-gcc CXX=riscv64-linux-gnu-g++ -j4
        echo "[3/6] Installing..."
        make install DESTDIR=$INSTALL_DIR prefix=/usr
        ;;
    *)
        echo "❌ Unknown build system: $BUILD_SYS"
        exit 1
        ;;
esac

# Create .deb
echo "[5/6] Creating .deb package..."
/mnt/d/rv-port-work/-rv-port-gurleen/scripts/create-deb.sh $PKG_NAME 1.0 $INSTALL_DIR

# Move .deb to releases directory
if [ -f "debs/${PKG_NAME}_1.0_riscv64.deb" ]; then
    mv "debs/${PKG_NAME}_1.0_riscv64.deb" /mnt/d/rv-port-work/-rv-port-gurleen/releases/
    echo "[6/6] ✅ Package moved to releases/"
else
    echo "[6/6] ⚠️ .deb not found, check create-deb.sh"
fi

# Cleanup
rm -rf $WORK_DIR $INSTALL_DIR

echo "=== $PKG_NAME build complete ==="
