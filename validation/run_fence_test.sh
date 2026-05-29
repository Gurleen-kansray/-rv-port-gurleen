#!/bin/bash
cd /mnt/d/rv-port-work/-rv-port-gurleen/validation

echo "=========================================="
echo "Minimal RVV Fence Test Suite"
echo "=========================================="

echo "[1/3] Compiling scalar..."
riscv64-linux-gnu-gcc -O2 -static -DUSE_FENCE=0 -o test_scalar minimal_rvv_fence_test.c

echo "[2/3] Compiling RVV without fence..."
riscv64-linux-gnu-gcc -O2 -static -march=rv64gcv -DUSE_RVV=1 -DUSE_FENCE=0 -o test_rvv_nofence minimal_rvv_fence_test.c

echo "[3/3] Compiling RVV with fence..."
riscv64-linux-gnu-gcc -O2 -static -march=rv64gcv -DUSE_RVV=1 -DUSE_FENCE=1 -o test_rvv_fence minimal_rvv_fence_test.c

echo ""
echo "--- SCALAR ---"
qemu-riscv64-static ./test_scalar

echo ""
echo "--- RVV WITHOUT FENCE ---"
qemu-riscv64-static ./test_rvv_nofence

echo ""
echo "--- RVV WITH FENCE ---"
qemu-riscv64-static ./test_rvv_fence
