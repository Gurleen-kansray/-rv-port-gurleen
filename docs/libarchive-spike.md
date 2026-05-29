
libarchive — riscv64 Cross-Compile Spike
Status: ✅ COMPLETE
Version: 3.7.4

Build Commands
bash
wget https://github.com/libarchive/libarchive/releases/download/v3.7.4/libarchive-3.7.4.tar.xz
tar -xJf libarchive-3.7.4.tar.xz
cd libarchive-3.7.4
./configure --host=riscv64-linux-gnu --prefix=/mnt/d/rv-workspace/libarchive-riscv64-install --disable-bsdtar --disable-bsdcat --disable-bsdcpio --without-xml2 --without-openssl --without-expat
make -j4 && make install
Verification
bash
file /mnt/d/rv-workspace/libarchive-riscv64-install/lib/libarchive.a
