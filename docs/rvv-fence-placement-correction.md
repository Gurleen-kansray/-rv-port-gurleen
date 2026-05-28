# RVV Fence Placement Correction (Issue #24)

## Initial Hypothesis
Memory ordering bug in QEMU RVV emulation (#3519)

## Investigation
Built verify-rvv-hot-path.sh to isolate issue
Found: Fence placement in MY kernel, not QEMU

## Root Cause
RVV dot product missing vseqvli barrier between accumulation phases
Result: Out-of-order execution produced 5-316x errors

## Fix Applied
```c
// WRONG: No barrier
vfmacc_vv(acc, a, b)
return vredsum(acc)

// RIGHT: Barrier before reduction
vsetvli(0, e64, m1)  // Force in-order
vfmacc_vv(acc, a, b)
return vredsum(acc)
Validation
Scalar: 50/50 PASS

RVV: 0/4 PASS → Fixed → 4/4 PASS

Locked in verify_fence_correctness.sh

Lesson
QEMU exposed correctness bug that hardware would also catch.
Not an emulator artifact.
