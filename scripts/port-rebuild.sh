#!/bin/bash
# port-rebuild.sh — automated port pipeline
# Usage: ./port-rebuild.sh ports/<package>/
set -e
PORT_DIR=$1
if [ -z "$PORT_DIR" ] || [ ! -d "$PORT_DIR" ]; then
    echo "Usage: $0 ports/<package>/"
    exit 1
fi

PKG=$(basename "$PORT_DIR")
echo "=== port-rebuild: $PKG ==="

# Step 1: Bootstrap
if [ -f "$PORT_DIR/bootstrap.sh" ]; then
    echo "[1/5] Bootstrapping..."
    bash "$PORT_DIR/bootstrap.sh"
else
    echo "[1/5] No bootstrap.sh — skipping"
fi

# Step 2: Build
if [ -f "$PORT_DIR/build.sh" ]; then
    echo "[2/5] Building..."
    bash "$PORT_DIR/build.sh"
else
    echo "[2/5] No build.sh — skipping"
fi

# Step 3: Verify RVV
if [ -f "$PORT_DIR/verify.conf" ]; then
    echo "[3/5] Verifying RVV..."
    BINARY=$(grep "^binary=" "$PORT_DIR/verify.conf" | cut -d= -f2)
    if [ -f "$BINARY" ]; then
        /home/acer/-rv-port-gurleen/scripts/rvv_per_func.sh "$BINARY"
    fi
else
    echo "[3/5] No verify.conf — skipping RVV check"
fi

# Step 4: Package
if [ -f "$PORT_DIR/package-deb.sh" ]; then
    echo "[4/5] Packaging..."
    bash "$PORT_DIR/package-deb.sh"
else
    echo "[4/5] No package-deb.sh — skipping"
fi

# Step 5: Smoke test
if [ -f "$PORT_DIR/smoke-test.sh" ]; then
    echo "[5/5] Smoke testing..."
    bash "$PORT_DIR/smoke-test.sh" && echo "✅ $PKG smoke test PASS" || echo "❌ $PKG smoke test FAIL"
else
    echo "[5/5] No smoke-test.sh — skipping"
fi

echo "=== port-rebuild: $PKG DONE ==="
