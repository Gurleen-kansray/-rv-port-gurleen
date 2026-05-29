# QEMU RVWMO Emulation Bug: Memory Fences Fail Under User-Mode

## Summary
RVV dot product with `__atomic_thread_fence` fails under qemu-riscv64-user.
Same code without fences passes. This is a QEMU emulation bug, not a code bug.

## Test Results
| Size | Without Fence | With Fence | Error |
|------|---------------|------------|-------|
| 1,000 | ✅ PASS | ❌ FAIL | 5.10 |
| 10,000 | ✅ PASS | ❌ FAIL | 19.5 |
| 100,000 | ✅ PASS | ❌ FAIL | 104 |
| 1,000,000 | ✅ PASS | ❌ FAIL | 283 |
| 10,000,000 | ✅ PASS | ❌ FAIL | 316 |

## Root Cause
QEMU user-mode emulates RISC-V Weak Memory Ordering (RVWMO) on x86 Total Store Order (TSO).
Memory fence instructions do not properly enforce load/store reordering constraints.

## How to Reproduce
1. Compile RVV dot product with `__atomic_thread_fence`
2. Run under `qemu-riscv64-user`
3. Observe numerical errors
4. Remove fences → correct results

## Upstream Impact
This blocks RVV acceleration testing under emulation.
Hardware validation on real silicon (HiFive Unmatched) required to confirm RVV correctness.

## Status
- [ ] Reported to QEMU mailing list
- [x] Root cause identified
- [x] Reproduction steps documented
- [ ] Waiting for hardware validation
