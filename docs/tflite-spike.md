# TensorFlow Lite 2.17.0 — riscv64 RVV Port

## Build
- Source: github.com/tensorflow/tensorflow v2.17.0
- Compiler: GCC 14 + `-march=rv64gcv`
- Blocker: missing `sys/hwprobe.h` — fixed with stub header

## RVV Results
- Full binary: 18,539 vsetvli, 19,750 arith ops, 106% ratio
- ML hot paths all vectorized

## Hot Path Attribution
| Function | Domain | Setup | Arith | Ratio |
|----------|--------|-------|-------|-------|
| FullyConnectedInt8 | FC layer INT8 | 22 | 64 | 278% |
| transpose_conv::Eval | Transpose conv | 59 | 137 | 228% |
| lstm_eval::EvalFloat | LSTM inference | 55 | 118 | 210% |
| optimized_ops::Conv | Convolution | 22 | 46 | 200% |
| ConvPerChannel | Quantized conv | 23 | 46 | 191% |

## Artifact
- `debs/tensorflow-lite-rvv_2.17.0_riscv64.deb`

## Status
✅ RVV validated under QEMU (GCC 14)
