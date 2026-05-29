#!/usr/bin/env python3
import subprocess
import csv
import sys
import os
from datetime import datetime

def build_package(name):
    print(f"\n{'='*50}")
    print(f"Building {name}")
    print(f"{'='*50}")
    result = subprocess.run(["./scripts/universal-builder.sh", name], 
                            capture_output=False)
    return result.returncode == 0

def main():
    os.chdir("/mnt/d/rv-port-work/-rv-port-gurleen")
    
    # Read package list
    packages = []
    with open("packages/database.csv", "r") as f:
        reader = csv.DictReader(f)
        for row in reader:
            packages.append(row["name"])
    
    print(f"Will build {len(packages)} packages")
    
    results = {}
    for pkg in packages:
        results[pkg] = build_package(pkg)
    
    # Summary
    print("\n" + "="*50)
    print("BUILD SUMMARY")
    print("="*50)
    passed = sum(1 for v in results.values() if v)
    failed = len(results) - passed
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    
    # Save report
    report = {
        "timestamp": datetime.now().isoformat(),
        "total": len(results),
        "passed": passed,
        "failed": failed,
        "results": results
    }
    import json
    with open("build_report.json", "w") as f:
        json.dump(report, f, indent=2)
    print("Report saved to build_report.json")

if __name__ == "__main__":
    main()
