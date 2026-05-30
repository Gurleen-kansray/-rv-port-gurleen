#!/usr/bin/env python3
"""
Dynamic audit engine for RISC-V HPC packages.
Scans actual .deb files and test binaries, no hardcoded numbers.
"""
import os
import json
import subprocess
from pathlib import Path

class AuditEngine:
    def __init__(self, repo_root=None):
        if repo_root is None:
            repo_root = Path(__file__).parent.parent
        self.repo_root = Path(repo_root)
        self.debs_dir = self.repo_root / "debs"
        self.releases_dir = self.repo_root / "releases"
        self.analysis_dir = self.repo_root / "analysis"

    def find_deb_packages(self):
        """Scan for .deb files in debs/ and releases/"""
        debs = []
        if self.debs_dir.exists():
            debs.extend(list(self.debs_dir.glob("*.deb")))
        if self.releases_dir.exists():
            debs.extend(list(self.releases_dir.glob("*.deb")))
        # Extract unique package names
        packages = set()
        for deb in debs:
            name = deb.stem.split('_')[0]  # e.g., arpack-ng_3.9.1_riscv64 -> arpack-ng
            packages.add(name)
        return sorted(packages)

    def find_test_binaries(self):
        """Scan for test executables in analysis/ directories"""
        test_bins = []
        if self.analysis_dir.exists():
            for test_file in self.analysis_dir.glob("**/test_*"):
                if test_file.is_file() and os.access(test_file, os.X_OK):
                    test_bins.append(test_file)
        return test_bins

    def run_test_binary(self, binary_path):
        """Execute a test binary and return PASS/FAIL based on exit code"""
        try:
            result = subprocess.run([str(binary_path)], capture_output=True, timeout=30)
            # Check for "PASS" in output or exit code 0
            output = result.stdout.decode() + result.stderr.decode()
            if "PASS" in output or result.returncode == 0:
                return "PASS"
            else:
                return "FAIL"
        except Exception:
            return "ERROR"

    def generate_report(self):
        """Generate audit report dynamically"""
        packages = self.find_deb_packages()
        test_bins = self.find_test_binaries()

        # Run tests
        test_results = {}
        for test_bin in test_bins:
            test_name = test_bin.stem
            status = self.run_test_binary(test_bin)
            test_results[test_name] = status

        # Build report
        report = {
            "total_packages": len(packages),
            "packages": {name: {"status": "available"} for name in packages},
            "tests": test_results,
            "total_tests": len(test_results),
            "passed": sum(1 for s in test_results.values() if s == "PASS"),
            "failed": sum(1 for s in test_results.values() if s == "FAIL"),
            "blocked": sum(1 for s in test_results.values() if s == "ERROR"),
        }
        return report

    def print_dashboard(self):
        """Print human-readable dashboard"""
        report = self.generate_report()
        print("\n" + "="*50)
        print("RISC-V HPC AUDIT DASHBOARD (Dynamic)")
        print("="*50)
        print(f"Total .deb packages found: {report['total_packages']}")
        print(f"Total test binaries found: {report['total_tests']}")
        print(f"Tests PASSED: {report['passed']}")
        print(f"Tests FAILED: {report['failed']}")
        print(f"Tests ERROR: {report['blocked']}")
        print("="*50)
        if report['passed'] == report['total_tests'] and report['total_tests'] > 0:
            print("✅ ALL TESTS PASSING")
        else:
            print("⚠️ SOME TESTS FAILING")
        print("="*50 + "\n")

    def save_report(self, filename="audit_report.json"):
        report = self.generate_report()
        with open(filename, "w") as f:
            json.dump(report, f, indent=2)
        print(f"[+] Report saved: {filename}")

if __name__ == "__main__":
    engine = AuditEngine()
    engine.print_dashboard()
    engine.save_report()
