# eBPF Observations on riscv64 under QEMU

## Overview
Real eBPF syscall profiling captured under `qemu-riscv64-static` for validated HPC packages.

## GetDP Profile (May 14, 2026)
- **Total syscalls:** 7,579
- **Top syscalls:**
  - `close`: 2,144 calls
  - `openat`: 332 calls
  - `futex`: 156 calls
- **Observation:** High `close` count indicates frequent file handle recycling in GetDP's magnetostatics solver.

## OOFEM Profile (May 14, 2026)
- **Top syscalls:**
  - `openat`: 570 calls
  - `mmap`: 211 calls
  - `futex`: 107 calls
- **Observation:** Memory mapping operations dominate OOFEM's structural mechanics workload.

## Methodology
```bash
sudo ./observability/syscall_profile.sh <binary> <duration>
```

## Raw Data
Captured profiles available in `/profiles` directory.

## Key Insight
eBPF profiling reveals that QEMU emulation overhead is dominated by `futex` (thread synchronization) and `openat`/`close` (file I/O) syscalls — not compute instructions.
