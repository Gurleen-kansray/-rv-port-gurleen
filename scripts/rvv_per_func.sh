#!/bin/bash
BINARY=$1
FUNC=$2
if [ -z "$FUNC" ]; then
  echo "=== Full binary RVV summary ==="
  SETUP=$(riscv64-linux-gnu-objdump -d "$BINARY" | grep -c "vsetvli\|vsetivli")
  ARITH=$(riscv64-linux-gnu-objdump -d "$BINARY" | grep -c "vle\|vse\|vfmacc\|vfmul\|vfadd")
  echo "Setup (vsetvli/vsetivli): $SETUP"
  echo "Arithmetic (vle/vse/vfmacc/vfmul/vfadd): $ARITH"
  echo "Ratio: $(echo "scale=0; $ARITH*100/$SETUP" | bc)%"
else
  echo "=== Per-function RVV: $FUNC ==="
  SETUP=$(riscv64-linux-gnu-objdump -d "$BINARY" | grep -A 500 "<$FUNC>" | grep -c "vsetvli\|vsetivli")
  ARITH=$(riscv64-linux-gnu-objdump -d "$BINARY" | grep -A 500 "<$FUNC>" | grep -c "vle\|vse\|vfmacc\|vfmul\|vfadd")
  echo "Setup: $SETUP"
  echo "Arithmetic: $ARITH"
  [ "$SETUP" -gt 0 ] && echo "Ratio: $(echo "scale=0; $ARITH*100/$SETUP" | bc)%" || echo "Ratio: N/A (scalar)"
fi
