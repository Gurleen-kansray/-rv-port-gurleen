# xxHash — riscv64 Cross-Compile Spike

**Status:** ✅ COMPLETE
**Version:** 0.8.3

## Build Commands
```bash
git clone https://github.com/Cyan4973/xxHash.git
cd xxHash
make CC=riscv64-linux-gnu-gcc CFLAGS="-O2 -march=rv64gc"
make install PREFIX=/mnt/d/rv-workspace/xxhash-riscv64-install
```

## Verification
```bash
file /mnt/d/rv-workspace/xxhash-riscv64-install/lib/libxxhash.a
```

## Impact
Fast hashing for riscv64.
