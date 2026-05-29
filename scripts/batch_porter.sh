#!/bin/bash
# Batch RISC-V HPC Code Porter
# Ports multiple codes in parallel, tracks success/failure

set -euo pipefail

TOOLCHAIN="$(pwd)/riscv64-linux-gnu.cmake"
CODES=(
  "https://github.com/dealii/dealii:deal.II"
  "https://github.com/fenics/dolfin:FEniCS-DOLFIN"
  "https://github.com/OpenFOAM/OpenFOAM-dev:OpenFOAM"
  "https://github.com/namsrai/Kratos:Kratos"
  "https://github.com/oofem/oofem:OOFEM"
)

RESULTS_DIR="batch_results_$(date +%Y%m%d_%H%M%S)"
mkdir -p "$RESULTS_DIR"

echo "🚀 Batch Porter: Porting ${#CODES[@]} codes in parallel"
echo "Results: $RESULTS_DIR"
echo ""

port_code() {
  local repo_url=$1
  local code_name=$2
  local result_file="$RESULTS_DIR/${code_name}.txt"
  
  echo "[$(date +%H:%M:%S)] Starting $code_name..." | tee "$result_file"
  
  cd /tmp
  git clone --depth 1 "$repo_url" "$code_name" 2>&1 | tee -a "$result_file" || {
    echo "❌ FAIL: Clone failed" | tee -a "$result_file"
    return 1
  }
  
  cd "$code_name"
  
  # Detect build system
  if [ -f CMakeLists.txt ]; then
    echo "📋 Detected: CMake" | tee -a "$result_file"
    mkdir -p build-riscv64
    cd build-riscv64
    
    if cmake -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
             -DCMAKE_BUILD_TYPE=Release .. 2>&1 | tee -a "$result_file"; then
      if make -j4 2>&1 | tee -a "$result_file" | tail -5; then
        echo "✅ PASS: $code_name built successfully" | tee -a "$result_file"
        return 0
      else
        echo "❌ FAIL: Make failed" | tee -a "$result_file"
        return 1
      fi
    else
      echo "❌ FAIL: CMake configure failed" | tee -a "$result_file"
      return 1
    fi
  else
    echo "⏭️  SKIP: Unknown build system" | tee -a "$result_file"
    return 2
  fi
}

# Port codes in parallel
for repo_and_name in "${CODES[@]}"; do
  repo_url="${repo_and_name%:*}"
  code_name="${repo_and_name#*:}"
  port_code "$repo_url" "$code_name" &
done

# Wait for all
wait

echo ""
echo "📊 Summary:"
echo ""
passed=0
failed=0
skipped=0

for result_file in "$RESULTS_DIR"/*.txt; do
  code=$(basename "$result_file" .txt)
  if grep -q "✅ PASS" "$result_file"; then
    echo "✅ $code"
    ((passed++))
  elif grep -q "❌ FAIL" "$result_file"; then
    echo "❌ $code"
    ((failed++))
  else
    echo "⏭️  $code"
    ((skipped++))
  fi
done

echo ""
echo "Results: $passed passed, $failed failed, $skipped skipped"
echo "Logs: $RESULTS_DIR/"

