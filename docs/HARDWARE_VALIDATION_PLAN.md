# Phase 4: Hardware Validation Strategy

## Objective
Validate riscv64 .deb packages run on **real RISC-V hardware** (not just QEMU).

## Hardware Options

**HiFive Unmatched:** $1,000 board, official SiFive dev platform
**VisionFive 2:** $50-80 board, practical for testing
**QEMU System Mode:** Fallback if hardware unavailable

## Validation Methodology

For each package on real hardware:

1. Install: `dpkg -i package_riscv64.deb`
2. Run test case (same as QEMU validation)
3. Compare numerical output (tolerance: 1e-12)
4. Document results

Example:
```bash
getdp problem.geo -solve MagSta -pos NoView
# x86 baseline: residual = 8.2729e-13
# RISC-V hardware: residual = 8.2728e-13
# Result: ✅ PASS (difference = 1e-14)
```

## Timeline

- **Weeks 1-8:** Port 8-12 CMake codes
- **Week 9:** Hardware arrives, begin validation
- **Weeks 9-10:** Run all packages on real silicon
- **Week 11:** Document discrepancies
- **Week 12:** Finalize handoff

## Success Criteria

✅ All 7 packages run without segfault
✅ Numerical output matches QEMU
✅ No QEMU vs hardware differences
✅ Full documentation complete

## Fallback Strategy

If hardware unavailable:
- Use QEMU system mode
- Document as "system-mode validation"
- Still proves RISC-V OS-level semantics work
