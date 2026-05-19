# FFTW – RISC-V Port

**Status:** ✅ COMPLETE (May 19, 2026)

**Build Method:** Release tarball fftw-3.3.10

**Build Commands:**
```bash
wget https://www.fftw.org/fftw-3.3.10.tar.gz
tar -xzvf fftw-3.3.10.tar.gz
cd fftw-3.3.10
./configure --host=riscv64-linux-gnu --disable-sse2 --disable-avx
make -j4
make check
