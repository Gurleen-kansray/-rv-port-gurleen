# Methodology Forensics

## Why Locked Gates Matter
- Traditional: "Tests pass"
- Ours: "Tests pass at EXACTLY these values"

## Backend-Specific Verification
When multiple backends exist, confirm via backend-specific opcode:
- Auto-vec: vsetvli (register-VL)
- Intrinsics: vsetivli (immediate-VL) 
- Hand-asm: vsetivli at entry, zero vsetvli after

## Arith/Setup Ratio as Silent-Fallback Detector
- Healthy: 10%-400% ratio
- Pathological: <1% (compiler bail)

## QEMU Exposes Correctness, Not Emulator Artifacts
When kernel fails by 1e3-1e5x → kernel has bug
QEMU's RVV is spec-correct. Hardware will show same failure.
