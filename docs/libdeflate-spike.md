
libdeflate — riscv64 Cross-Compile Spike
Status: ✅ COMPLETE

Build Commands
bash
git clone https://github.com/ebiggers/libdeflate.git
cd libdeflate
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/mnt/d/rv-workspace/-rv-port-gurleen/riscv64-toolchain.cmake -DCMAKE_INSTALL_PREFIX=/mnt/d/rv-workspace/libdeflate-riscv64-install
make -j4 && make install
Verification
bash
file /mnt/d/rv-workspace/libdeflate-riscv64-install/lib/libdeflate.a
