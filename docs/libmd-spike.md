
libmd — riscv64 Cross-Compile Spike
Status: ✅ COMPLETE
Version: 1.1.0

Build Commands
bash
wget https://libbsd.freedesktop.org/releases/libmd-1.1.0.tar.xz
tar -xJf libmd-1.1.0.tar.xz
cd libmd-1.1.0
./configure --host=riscv64-linux-gnu --prefix=/mnt/d/rv-workspace/libmd-riscv64-install
make -j4 && make install
Verification
bash
file /mnt/d/rv-workspace/libmd-riscv64-install/lib/libmd.a
