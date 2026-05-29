#!/bin/bash
# Phase 4 Hardware Validation Script
# Run on real RISC-V hardware (HiFive Unmatched, VisionFive2)
# This measures actual performance vs QEMU predictions

set -euo pipefail

HARDWARE=$(uname -m)
HOSTNAME=$(hostname)
TIMESTAMP=$(date -u +%Y-%m-%dT%H:%M:%SZ)

echo "🔬 Phase 4 Hardware Validation"
echo "Hardware: $HARDWARE"
echo "Host: $HOSTNAME"
echo "Time: $TIMESTAMP"
echo ""

RESULTS_FILE="hardware_results_${HOSTNAME}_$(date +%Y%m%d_%H%M%S).json"

# Initialize JSON
cat > $RESULTS_FILE << JSON_START
{
  "metadata": {
    "timestamp": "$TIMESTAMP",
    "hostname": "$HOSTNAME",
    "architecture": "$HARDWARE",
    "validation_type": "phase_4_hardware"
  },
  "tests": [
JSON_START

# Test 1: DGEMM scalar validation
if [ -f "analysis/dgemm/test_dgemm_extended_50cases" ]; then
  echo "Testing DGEMM (50 cases)..."
  start=$(date +%s%N)
  analysis/dgemm/test_dgemm_extended_50cases > /tmp/dgemm.out 2>&1 || true
  end=$(date +%s%N)
  elapsed=$(( (end - start) / 1000000 ))
  
  if grep -q "50/50 PASS" /tmp/dgemm.out; then
    result="PASS"
    error_count=0
  else
    result="FAIL"
    error_count=$(grep -c "FAIL" /tmp/dgemm.out || echo "unknown")
  fi
  
  cat >> $RESULTS_FILE << JSON_TEST1
    {
      "test": "dgemm_50cases",
      "result": "$result",
      "elapsed_ms": $elapsed,
      "error_count": $error_count
    },
JSON_TEST1
fi

# Test 2: BLAS L1/L2/L3 validation
if [ -f "analysis/blas/test_blas_l1_l2_l3_complete" ]; then
  echo "Testing BLAS L1/L2/L3 (61 operations)..."
  start=$(date +%s%N)
  analysis/blas/test_blas_l1_l2_l3_complete > /tmp/blas.out 2>&1 || true
  end=$(date +%s%N)
  elapsed=$(( (end - start) / 1000000 ))
  
  if grep -q "61/61 PASS" /tmp/blas.out; then
    result="PASS"
    error_count=0
  else
    result="FAIL"
    error_count=$(grep -c "FAIL" /tmp/blas.out || echo "unknown")
  fi
  
  cat >> $RESULTS_FILE << JSON_TEST2
    {
      "test": "blas_l1_l2_l3_61ops",
      "result": "$result",
      "elapsed_ms": $elapsed,
      "error_count": $error_count
    },
JSON_TEST2
fi

# Test 3: LAPACK validation
if [ -f "analysis/lapack/test_lapack_complete" ]; then
  echo "Testing LAPACK (27 routines)..."
  start=$(date +%s%N)
  analysis/lapack/test_lapack_complete > /tmp/lapack.out 2>&1 || true
  end=$(date +%s%N)
  elapsed=$(( (end - start) / 1000000 ))
  
  if grep -q "27/27 PASS" /tmp/lapack.out; then
    result="PASS"
    error_count=0
  else
    result="FAIL"
    error_count=$(grep -c "FAIL" /tmp/lapack.out || echo "unknown")
  fi
  
  cat >> $RESULTS_FILE << JSON_TEST3
    {
      "test": "lapack_27routines",
      "result": "$result",
      "elapsed_ms": $elapsed,
      "error_count": $error_count
    }
JSON_TEST3
fi

# Close JSON
cat >> $RESULTS_FILE << JSON_END
  ],
  "summary": {
    "total_operations_validated": 138,
    "validation_framework": "phase4_hardware",
    "notes": "Validation on real RISC-V hardware. Compare with QEMU baseline."
  }
}
JSON_END

echo ""
echo "✅ Validation complete. Results saved to:"
echo "   $RESULTS_FILE"
echo ""
cat $RESULTS_FILE

