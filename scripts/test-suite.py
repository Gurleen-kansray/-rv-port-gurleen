#!/usr/bin/env python3
"""
RISC-V HPC Package Test Suite
Validates all 7 packages
"""

import subprocess
import json
from datetime import datetime
import os

PACKAGES = {
    "openblas": "libopenblas_0.3.33_riscv64.deb",
    "spooles": "spooles_2.2_riscv64.deb",
    "arpack": "arpack-ng_3.9.1_riscv64.deb",
    "getdp": "getdp_4.0.0_riscv64.deb",
    "oofem": "oofem_2.6_riscv64.deb",
    "calculix": "calculix-ccx_2.21_riscv64.deb",
    "elmer": "elmer_9.0_riscv64.deb"
}

DEB_DIR = os.path.expanduser("~/risc-v-hpc/debs")

def test_package(name, deb_file):
    """Test a single package"""
    print(f"\n{'='*60}")
    print(f"Testing {name.upper()}")
    print(f"{'='*60}")
    
    deb_path = os.path.join(DEB_DIR, deb_file)
    
    if not os.path.exists(deb_path):
        print(f"❌ {name}: FILE NOT FOUND")
        print(f"   Expected at: {deb_path}")
        return {"name": name, "status": "NOT_FOUND", "file": deb_file}
    
    try:
        # Check if it's a valid .deb
        result = subprocess.run(
            ["file", deb_path],
            capture_output=True,
            text=True,
            timeout=5
        )
        
        if "Debian" in result.stdout or "ar archive" in result.stdout:
            # Get file size
            size_mb = os.path.getsize(deb_path) / (1024*1024)
            print(f"✅ {name}: VALID .deb")
            print(f"   File: {deb_file}")
            print(f"   Size: {size_mb:.1f} MB")
            return {"name": name, "status": "PASS", "file": deb_file, "size_mb": size_mb}
        else:
            print(f"❌ {name}: NOT A VALID .deb")
            print(f"   Got: {result.stdout}")
            return {"name": name, "status": "INVALID", "file": deb_file}
            
    except Exception as e:
        print(f"❌ {name}: ERROR - {str(e)}")
        return {"name": name, "status": "ERROR", "file": deb_file}

def main():
    print("\n" + "="*60)
    print("RISC-V HPC PACKAGE TEST SUITE")
    print("="*60)
    print(f"Started: {datetime.now().isoformat()}")
    print(f"Debs directory: {DEB_DIR}")
    
    results = []
    passed = 0
    failed = 0
    
    for pkg_name, deb_file in PACKAGES.items():
        result = test_package(pkg_name, deb_file)
        results.append(result)
        
        if result["status"] == "PASS":
            passed += 1
        else:
            failed += 1
    
    # Summary
    print("\n" + "="*60)
    print("TEST SUMMARY")
    print("="*60)
    print(f"Total packages: {len(PACKAGES)}")
    print(f"Valid .deb files: {passed} ✅")
    print(f"Missing/Invalid: {failed} ❌")
    print(f"Success Rate: {(passed/len(PACKAGES)*100):.1f}%")
    
    # Calculate total size
    total_size = sum(r.get("size_mb", 0) for r in results)
    print(f"Total .deb size: {total_size:.1f} MB")
    
    # Save report
    report = {
        "timestamp": datetime.now().isoformat(),
        "total": len(PACKAGES),
        "passed": passed,
        "failed": failed,
        "total_size_mb": total_size,
        "results": results
    }
    
    with open("test-results.json", "w") as f:
        json.dump(report, f, indent=2)
    
    print(f"\nDetailed report: test-results.json")
    print("="*60)
    
    return 0 if failed == 0 else 1

if __name__ == "__main__":
    exit(main())
