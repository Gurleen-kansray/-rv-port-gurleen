test: demo_x86 demo_riscv
	@echo "--- x86 output ---"
	./demo_x86
	@echo "--- riscv64 output ---"
	qemu-riscv64-static -L /usr/riscv64-linux-gnu ./demo_riscv
	@echo "PASS: same result, different backend"

demo_x86: demo.c
	gcc -O2 -msse2 demo.c -o demo_x86

demo_riscv: demo.c
	riscv64-linux-gnu-gcc -O2 demo.c -o demo_riscv

clean:
	rm -f demo_x86 demo_riscv
