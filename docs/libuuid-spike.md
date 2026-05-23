# libuuid — riscv64 Cross-Compile Spike

**Status:** ✅ COMPLETE
**Version:** 2.39.3

## Build Commands
```bash
wget https://mirrors.edge.kernel.org/pub/linux/utils/util-linux/v2.39/util-linux-2.39.3.tar.xz
tar -xJf util-linux-2.39.3.tar.xz
cd util-linux-2.39.3
./configure --host=riscv64-linux-gnu --prefix=/mnt/d/rv-workspace/libuuid-riscv64-install --disable-all-programs --enable-libuuid
make -j4 && make install
Verification
bash
file /mnt/d/rv-workspace/libuuid-riscv64-install/lib/libuuid.a
# Output: current ar archive
