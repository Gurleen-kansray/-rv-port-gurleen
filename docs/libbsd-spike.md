
libbsd — riscv64 Cross-Compile Spike
Status: ✅ COMPLETE
Version: 0.12.2

Build Commands
bash
wget https://libbsd.freedesktop.org/releases/libbsd-0.12.2.tar.xz
tar -xJf libbsd-0.12.2.tar.xz
cd libbsd-0.12.2
./configure --host=riscv64-linux-gnu --prefix=/mnt/d/rv-workspace/libbsd-riscv64-install --with-libmd=/mnt/d/rv-workspace/libmd-riscv64-install
make -j4 && make install
Verification
bash
file /mnt/d/rv-workspace/libbsd-riscv64-install/lib/libbsd.a
