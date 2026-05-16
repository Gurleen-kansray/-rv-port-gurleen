#!/usr/bin/env python3

import os
import subprocess
import csv
from pathlib import Path

PORTS_DIR = "../ports"
RESULTS_FILE = "build-status.csv"

results = []

packages = [d for d in os.listdir(PORTS_DIR) 
           if os.path.isdir(os.path.join(PORTS_DIR, d))]

for pkg in sorted(packages):
    pkg_path = os.path.join(PORTS_DIR, pkg)
    build_path = os.path.join(pkg_path, "build-riscv64")
    deb_files = list(Path(pkg_path).glob("*_riscv64.deb"))
    
    if deb_files:
        status = "✅ BUILT"
        deb_file = os.path.basename(deb_files[0])
        size = os.path.getsize(deb_files[0]) / (1024*1024)
        notes = f"{deb_file} ({size:.1f}MB)"
    elif os.path.exists(build_path):
        if os.path.exists(os.path.join(build_path, "Makefile")):
            status = "🏗️ COMPILED"
            notes = "Not packaged yet"
        else:
            status = "❌ FAILED"
            notes = "Build failed or incomplete"
    else:
        status = "⏳ NOT_STARTED"
        notes = "Build directory empty"
    
    results.append({
        'Package': pkg,
        'Status': status,
        'Path': pkg_path,
        'Notes': notes
    })

# Print table
print("\n" + "="*80)
print("RISC-V HPC PORTING STATUS")
print("="*80)
print(f"{'Package':<15} {'Status':<15} {'Notes':<50}")
print("-"*80)

for r in results:
    print(f"{r['Package']:<15} {r['Status']:<15} {r['Notes']:<50}")

print("="*80 + "\n")

# Count summary
built = sum(1 for r in results if "✅" in r['Status'])
compiled = sum(1 for r in results if "🏗️" in r['Status'])
failed = sum(1 for r in results if "❌" in r['Status'])
not_started = sum(1 for r in results if "⏳" in r['Status'])

print(f"Summary: {built} Built | {compiled} Compiled | {failed} Failed | {not_started} Not Started")
print(f"Total Packages: {len(results)}\n")

# Write CSV
with open(RESULTS_FILE, 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['Package', 'Status', 'Notes'])
    writer.writeheader()
    writer.writerows(results)

print(f"Detailed report written to {RESULTS_FILE}")
