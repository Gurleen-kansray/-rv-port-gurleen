#!/bin/bash
# One-command script to reproduce all findings

echo "=== Reproducing Sync Overhead Data ==="

# GetDP
echo "GetDP sync overhead:"
strace -c -f -e trace=futex,sched_yield qemu-riscv64-static -L /usr/riscv64-linux-gnu ./debs/getdp-riscv64/usr/bin/getdp --help 2>&1 | grep -E "futex|sched_yield"

# OOFEM
echo "OOFEM sync overhead:"
strace -c -f -e trace=futex,sched_yield qemu-riscv64-static -L /usr/riscv64-linux-gnu ./debs/oofem-riscv64/usr/bin/oofem -v 2>&1 | grep -E "futex|sched_yield"

# ARPACK
echo "ARPACK sync overhead:"
strace -c -f -e trace=futex,sched_yield qemu-riscv64-static -L /usr/riscv64-linux-gnu ./arpack-threaded/build/TESTS/bug_58_double 2>&1 | grep -E "futex|sched_yield"

# Compute benchmark
echo "Compute benchmark:"
./analysis/ebpf/compute_bench

echo "=== All findings reproduced ==="
