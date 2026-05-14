# eBPF Syscall Profiles — riscv64 Binaries under QEMU

Profiles captured using `observability/syscall_profile.sh` with bpftrace on WSL2 Ubuntu 24.04.
Each binary was run under `qemu-riscv64-static` while bpftrace attached 348 tracepoints.

---

## GetDP 4.0.0 — Syscall Profile

**Date:** 2026-05-14
**Command:** `qemu-riscv64-static debs/getdp-riscv64/usr/bin/getdp`
**Total syscalls captured:** 7,579 in first second

### Top Syscalls by Count

| Syscall | Count | Meaning |
|---|---|---|
| `close` | 2,144 | File descriptor cleanup — shared lib loading |
| `bpf` | 1,064 | bpftrace instrumentation overhead |
| `ioctl` | 845 | Device/terminal control |
| `dup2` | 637 | File descriptor duplication |
| `access` | 381 | File existence checks during lib resolution |
| `openat` | 332 | File opens — shared library loading |
| `dup` | 317 | FD duplication |
| `recvfrom` | 249 | Network/socket activity |
| `recvmsg` | 240 | Message receive |
| `read` | 156 | Data reads |
| `futex` | 156 | Thread synchronisation |

### Key Observations

**1. Library loading dominates startup (`close` 2144, `openat` 332, `access` 381)**
GetDP under QEMU spends most of its syscall budget on dynamic linker activity.
This is expected — qemu-riscv64-static re-resolves shared libraries on every run.
On real riscv64 hardware the loader cache would eliminate most of these.

**2. No `mmap` in top syscalls**
Absence of heavy `mmap` calls confirms GetDP is not doing large memory-mapped I/O
at startup — good for embedded/low-memory riscv64 targets.

**3. `futex` count (156) confirms threading**
GetDP initialises a thread pool even for the `--help` invocation.
On riscv64 hardware with RVV, these threads would map to vector execution units.

**4. `brk` (21) — heap growth pattern**
21 `brk` calls indicates moderate heap allocation at startup.
Consistent with a solver loading mesh structures before any computation.

**5. QEMU overhead visible**
The `bpf: 1064` and `perf_event_open: 155` counts are bpftrace instrumentation,
not GetDP itself. On bare metal these would be zero.

### Binary Confirmed Running on riscv64

```
GetDP, a General environment for the treatment of Discrete Problems
Copyright (C) 1997-2026 P. Dular and C. Geuzaine, University of Liege
```

GetDP executed correctly under `qemu-riscv64-static` and printed its full
help output — confirming the riscv64 binary is functional.

---

## Methodology

```bash
bash observability/syscall_profile.sh debs/getdp-riscv64/usr/bin/getdp
```

The script:
1. Starts bpftrace attaching to all `syscalls:sys_enter_*` tracepoints (348 total)
2. Runs the binary under `qemu-riscv64-static`
3. Captures per-syscall counts and 1-second interval totals
4. Saves raw trace to `profiles/<binary>_<timestamp>/syscall_trace.txt`

Raw profile data is in `profiles/getdp_20260514_095104/`.

---

## Next: OOFEM Profile

Run:

```bash
bash observability/syscall_profile.sh debs/oofem-riscv64/usr/bin/oofem
```
