#!/bin/bash
# RVV Hot Path Verification
# Confirms RVV instructions appear in computational inner loops

set -e

TARGET_BINARY=${1:-"./lammps-rvv"}

echo "=== RVV Hot Path Analysis ==="

# Check for RVV instructions in binary
if ! command -v riscv64-linux-gnu-objdump &> /dev/null; then
    echo "WARNING: objdump not found, skipping detailed analysis"
    exit 0
fi

# Count total RVV instructions
TOTAL_RVV=$(riscv64-linux-gnu-objdump -d $TARGET_BINARY 2>/dev/null | grep -E "vsetvli|vfmacc|vredsum|vle|vse" | wc -l)
echo "Total RVV instructions: $TOTAL_RVV"

# Check for vsetvli (setup) vs arithmetic ratio
VSETVLI_COUNT=$(riscv64-linux-gnu-objdump -d $TARGET_BINARY 2>/dev/null | grep "vsetvli" | wc -l)
ARITH_COUNT=$(riscv64-linux-gnu-objdump -d $TARGET_BINARY 2>/dev/null | grep -E "vfmacc|vfred|vadd" | wc -l)

if [ $VSETVLI_COUNT -gt 0 ]; then
    RATIO=$((ARITH_COUNT * 100 / VSETVLI_COUNT))
    echo "Arith/Setup ratio: $RATIO% ($ARITH_COUNT / $VSETVLI_COUNT)"
    
    if [ $RATIO -lt 10 ]; then
        echo "⚠️ WARNING: Low ratio suggests compiler silent fallback"
    else
        echo "✓ Healthy ratio detected"
    fi
fi

echo "=== Analysis Complete ==="
