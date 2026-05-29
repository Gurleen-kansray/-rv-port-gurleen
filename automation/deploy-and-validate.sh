#!/bin/bash
# deploy-and-validate.sh - Automatically fetch release .deb files, install, and validate
# Usage: ./automation/deploy-and-validate.sh [release-tag]

set -e

RELEASE_TAG=${1:-v2.0.0}
REPO="Gurleen-kansray/-rv-port-gurleen"
WORK_DIR="/tmp/riscv-deploy-$$"
LOG_FILE="$WORK_DIR/deploy.log"

mkdir -p "$WORK_DIR"
cd "$WORK_DIR"

echo "=== Deploy and Validate Automation ==="
echo "Release: $RELEASE_TAG"
echo "Log: $LOG_FILE"

# Step 1: Get release assets list
echo "[1/5] Fetching release assets..."
API_URL="https://api.github.com/repos/$REPO/releases/tags/$RELEASE_TAG"
DEB_URLS=$(curl -s "$API_URL" | grep -o '"browser_download_url": "[^"]*\.deb"' | cut -d '"' -f 4)

if [ -z "$DEB_URLS" ]; then
    echo "❌ No .deb files found in release $RELEASE_TAG"
    exit 1
fi

DEB_COUNT=$(echo "$DEB_URLS" | wc -l)
echo "Found $DEB_COUNT .deb files"

# Step 2: Download all .deb files
echo "[2/5] Downloading .deb files..."
echo "$DEB_URLS" | while read url; do
    filename=$(basename "$url")
    echo "  Downloading $filename..."
    curl -L -s -o "$filename" "$url"
done

# Step 3: Set up temporary installation environment (using dpkg --force-depends)
echo "[3/5] Installing .deb packages..."
DEB_FILES=$(ls *.deb)
# Try to install in order (smaller dependencies first)
sudo dpkg -i --force-depends $DEB_FILES 2>&1 | tee -a "$LOG_FILE" || true

# Step 4: Run validation
echo "[4/5] Running validation..."
cd /mnt/d/rv-port-work/-rv-port-gurleen
if [ -f "verify_gurleen_port.py" ]; then
    python3 verify_gurleen_port.py 2>&1 | tee -a "$LOG_FILE"
    if [ ${PIPESTATUS[0]} -eq 0 ]; then
        echo "✅ Validation passed"
        VALID_STATUS="PASS"
    else
        echo "❌ Validation failed"
        VALID_STATUS="FAIL"
    fi
else
    echo "⚠️ verify_gurleen_port.py not found"
    VALID_STATUS="UNKNOWN"
fi

# Step 5: Cleanup
echo "[5/5] Cleaning up..."
# Keep logs but remove downloaded .deb files
rm -rf "$WORK_DIR"/*.deb

echo ""
echo "=== Automation Summary ==="
echo "Release: $RELEASE_TAG"
echo "Packages deployed: $DEB_COUNT"
echo "Validation result: $VALID_STATUS"
echo "Log saved to: $LOG_FILE"
