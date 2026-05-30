#!/bin/bash
riscv64-linux-gnu-gcc-14 -O3 -march=rv64gcv -static -fopenmp /mnt/d/stream/stream.c -o /tmp/stream-rvv -lm && echo "built"
