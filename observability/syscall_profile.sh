#!/bin/bash
set -e

BINARY=$1
QEMU_PREFIX=/usr/riscv64-linux-gnu

if [ -z "$BINARY" ]; then
    echo "Usage: $0 <path-to-riscv64-binary>"
    exit 1
fi

OUTPUT_DIR="profiles/$(basename $BINARY)_$(date +%Y%m%d_%H%M%S)"
mkdir -p "$OUTPUT_DIR"

echo "Starting eBPF syscall profiling for $(basename $BINARY)..."
echo "Output: $OUTPUT_DIR"

# Start bpftrace in background
sudo bpftrace -e '
tracepoint:syscalls:sys_enter_* 
{ 
    @syscalls[probe] = count(); 
    @total = count();
}
interval:s:1 
{
    time("%H:%M:%S ");
    print(@total);
    clear(@total);
}
END 
{
    printf("\n=== Syscall Profile ===\n");
    print(@syscalls);
}
' > "$OUTPUT_DIR/syscall_trace.txt" 2>&1 &

BPFTRACE_PID=$!
sleep 2

# Run the binary under QEMU
qemu-riscv64-static -L "$QEMU_PREFIX" "$BINARY" > "$OUTPUT_DIR/binary_output.txt" 2>&1

# Give bpftrace time to collect data
sleep 2

# Stop bpftrace
sudo kill -INT $BPFTRACE_PID
wait $BPFTRACE_PID 2>/dev/null || true

echo "Profile complete: $OUTPUT_DIR/syscall_trace.txt"
echo "Binary output: $OUTPUT_DIR/binary_output.txt"
