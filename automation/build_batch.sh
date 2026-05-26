#!/bin/bash
# Batch builder for RISC-V HPC packages

TIMESTAMP=$(date +%Y%m%d_%H%M%S)
BATCH_LOG="/mnt/d/rv-port/automation/logs/batch_${TIMESTAMP}.log"
mkdir -p /mnt/d/rv-port/automation/logs

PACKAGES=(
    "openblas:https://github.com/xianyi/OpenBLAS.git"
    "lapack:https://github.com/Reference-LAPACK/lapack.git"
    "arpack:https://github.com/opencollab/arpack-ng.git"
)

PASSED=0
FAILED=0
FAILED_PACKAGES=()

echo "=== RISC-V HPC Batch Build ===" | tee "$BATCH_LOG"
echo "Starting: $(date)" | tee -a "$BATCH_LOG"

for PKG in "${PACKAGES[@]}"; do
    IFS=':' read -r NAME URL <<< "$PKG"
    echo "Building $NAME..." | tee -a "$BATCH_LOG"
    
    if /mnt/d/rv-port/automation/scripts/build_package.sh "$NAME" "$URL" >> "$BATCH_LOG" 2>&1; then
        echo "✅ $NAME" | tee -a "$BATCH_LOG"
        ((PASSED++))
    else
        echo "❌ $NAME" | tee -a "$BATCH_LOG"
        ((FAILED++))
        FAILED_PACKAGES+=("$NAME")
    fi
done

echo "=== Build Summary ===" | tee -a "$BATCH_LOG"
echo "Passed: $PASSED" | tee -a "$BATCH_LOG"
echo "Failed: $FAILED" | tee -a "$BATCH_LOG"
echo "Finished: $(date)" | tee -a "$BATCH_LOG"

if [ $FAILED -gt 0 ]; then
    echo "Failed packages: ${FAILED_PACKAGES[*]}" | tee -a "$BATCH_LOG"
fi
