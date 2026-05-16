#!/bin/bash

# Color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# List of packages to build
PACKAGES=(
  "elmer"
  "getdp"
  "oofem"
  "spooles"
  "openblas"
  "arpack"
)

RESULTS_FILE="build-results.csv"
echo "Package,Status,Build_Time,Notes" > $RESULTS_FILE

for pkg in "${PACKAGES[@]}"; do
  echo -e "${YELLOW}Building $pkg...${NC}"
  
  if [ ! -d "../ports/$pkg" ]; then
    echo "$pkg,SKIPPED,0,Directory not found" >> $RESULTS_FILE
    echo -e "${YELLOW}⊘ Skipping $pkg (not downloaded)${NC}\n"
    continue
  fi
  
  cd ../ports/$pkg
  
  # Check if already built
  if [ -f "build-riscv64/Makefile" ] && [ -f "*_riscv64.deb" ]; then
    echo "$pkg,PASS,cached,Already built" >> ../../../scripts/$RESULTS_FILE
    echo -e "${GREEN}✅ $pkg already built${NC}\n"
    cd ../../../scripts
    continue
  fi
  
  # Clean previous build
  rm -rf build-riscv64
  mkdir -p build-riscv64
  
  # Time the build
  START=$(date +%s)
  cd build-riscv64
  
  # Configure
  if cmake \
    -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CROSSCOMPILING_EMULATOR=qemu-riscv64-static \
    .. 2>&1 | tee configure.log > /dev/null; then
    
    # Build
    if make -j4 2>&1 | tee build.log > /dev/null; then
      END=$(date +%s)
      BUILD_TIME=$((END - START))
      echo "$pkg,PASS,$BUILD_TIME,Success" >> ../../../scripts/$RESULTS_FILE
      echo -e "${GREEN}✅ $pkg built successfully ($BUILD_TIME seconds)${NC}\n"
    else
      END=$(date +%s)
      BUILD_TIME=$((END - START))
      ERROR=$(tail -3 build.log | tr '\n' ';')
      echo "$pkg,FAIL,$BUILD_TIME,$ERROR" >> ../../../scripts/$RESULTS_FILE
      echo -e "${RED}❌ $pkg build failed${NC}\n"
    fi
  else
    ERROR=$(tail -3 configure.log | tr '\n' ';')
    echo "$pkg,FAIL,0,Configure error - $ERROR" >> ../../../scripts/$RESULTS_FILE
    echo -e "${RED}❌ $pkg configure failed${NC}\n"
  fi
  
  cd ../../../scripts
done

echo -e "\n${GREEN}=== BUILD SUMMARY ===${NC}"
cat $RESULTS_FILE
