#!/bin/bash
# Batch builder for RISC-V HPC packages
# Demonstrates production automation pipeline

TIMESTAMP=$(date +%Y%m%d_%H%M%S)
BATCH_LOG="automation/logs/batch_${TIMESTAMP}.log"
mkdir -p automation/logs

PACKAGES=(
    "openopenblas:https://github.com/xianyi/OpenBLAS.git"
    "lapack:https://github.com/Reference-LAPACK/lapack.git"
    "arpack:https://github.com/opencollab/arpack-ng.git"
)

PASSED=0
FAILED=0

echo "=== RISC-V HPC Batch Build ===" | tee "$BATCH_LOG"
echo "Starting: $(date)" | tee -a "$BATCH_LOG"

for PKG in "${PACKAGES[@]}"; do
    IFS=':' read -r NAME URL <<< "$PKG"
    
    if ./automation/scripts/build_package.sh "$NAME" "$URL" >> "$BATCH_LOG" 2>&1; then
        echo "✅ $NAME" | tee -a "$BATCH_LOG"
        ((PASSED++))
    else
        echo "❌ $NAME" | tee -a "$BATCH_LOG"
        ((FAILED++))
    fi
done

echo "" | tee -a "$BATCH_LOG"
echo "=== Summary ===" | tee -a "$BATCH_LOG"
echo "Passed: $PASSED | Failed: $FAILED" | tee -a "$BATCH_LOG"
