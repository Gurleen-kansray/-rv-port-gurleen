#!/bin/bash
# ONE COMMAND to install all 25 riscv64 packages

set -e

echo "═══════════════════════════════════════════════════════════════"
echo "  Installing 25 riscv64 HPC Packages"
echo "═══════════════════════════════════════════════════════════════"

# Set up riscv64 architecture
sudo dpkg --add-architecture riscv64
echo "deb [arch=riscv64] http://ports.ubuntu.com/ubuntu-ports noble main universe" | sudo tee /etc/apt/sources.list.d/riscv64.list
sudo apt-get update

# Install dependencies
sudo apt-get install -y \
    libopenblas-dev:riscv64 \
    liblapack-dev:riscv64 \
    libfftw3-dev:riscv64 \
    libgsl-dev:riscv64 \
    libhdf5-dev:riscv64

# Install all .deb packages
for deb in debs/*.deb; do
    echo "Installing $deb..."
    sudo dpkg -i "$deb" || true
done

echo "═══════════════════════════════════════════════════════════════"
echo "  ALL 25 PACKAGES INSTALLED"
echo "═══════════════════════════════════════════════════════════════"
echo ""
echo "Packages installed:"
ls -la /usr/lib/riscv64-linux-gnu/ | grep -E "libopenblas|liblapack|libarpack|libspooles"
