#!/usr/bin/env python3
import json
from pathlib import Path

data = json.loads(Path("/mnt/d/rv-port-gurleen/master_report.json").read_text())
rvv_data = json.loads(Path("/mnt/d/rv-port-gurleen/rvv_audit_results.json").read_text())

lines = []
lines.append("# HPC riscv64 — Master Dashboard")
lines.append(f"Generated: {data['generated']}\n")

s = data['summary']
lines.append(f"## Summary")
lines.append(f"| Total | Pass | Fail | RVV | Scalar |")
lines.append(f"|-------|------|------|-----|--------|")
rv = data['rvv_summary']
lines.append(f"| {s['total']} | {s['passed']} | {s['failed']} | {rv['rvv_packages']} | {rv['scalar_packages']} |\n")

lines.append("## RVV Compliance Matrix")
lines.append("| Package | Version | vsetvli | Arith | Ratio | Status |")
lines.append("|---------|---------|---------|-------|-------|--------|")
for pkg in data['packages']:
    r = pkg.get('rvv')
    if r and r.get('rvv'):
        ratio = r['ratio_pct']
        lines.append(f"| {pkg['name']} | {pkg['version']} | {r['setup']} | {r['arith']} | {ratio}% | ✅ RVV |")

lines.append("\n## Scalar Packages")
lines.append("| Package | Version | ELF | Size KB |")
lines.append("|---------|---------|-----|---------|")
for pkg in data['packages']:
    r = pkg.get('rvv')
    if not r or not r.get('rvv'):
        lines.append(f"| {pkg['name']} | {pkg['version']} | {pkg.get('elf','—')} | {pkg['size_kb']} |")

out = Path("/mnt/d/rv-port-gurleen/DASHBOARD.md")
out.write_text("\n".join(lines))
print("✅ Saved: DASHBOARD.md")
print("\n".join(lines[:30]))
