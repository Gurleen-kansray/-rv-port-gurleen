#!/usr/bin/env python3
# audit_engine_v2.py — HPC riscv64 package auditor + dependency graph
# Scans debs/ (and releases/, repo root) for .deb files,
# verifies Architecture: riscv64, checks ELF binaries,
# and generates an interactive HTML dependency graph (hpc_graph.html).
# Usage:
#   python3 automation/audit_engine_v2.py --all --debs-dir debs
#   python3 automation/audit_engine_v2.py --all --debs-dir debs --no-elf
# Output:
#   audit_report_v2.json  — machine-readable summary + per-package results
#   hpc_graph.html        — interactive dependency graph, open in browser

import json, subprocess, tempfile, shutil, argparse
from datetime import datetime
from pathlib import Path

# Repo root is two levels up from this script (automation/audit_engine_v2.py)
REPO_ROOT = Path(__file__).resolve().parent.parent
# Primary search dir; override with --debs-dir
DEBS_DIR = REPO_ROOT / "debs"

# HPC dependency graph: key depends on listed packages
# Categories: foundation | math | solver | io | sim | ml
DEPS = {
    "openblas-riscv64":      {"deps": [],                                                              "cat": "foundation", "label": "OpenBLAS"},
    "openblas-rvv":          {"deps": [],                                                              "cat": "foundation", "label": "OpenBLAS RVV"},
    "lapack":                {"deps": ["openblas-riscv64"],                                            "cat": "math",       "label": "LAPACK"},
    "arpack-ng-rvv":         {"deps": ["openblas-riscv64", "lapack"],                                  "cat": "math",       "label": "ARPACK-ng"},
    "spooles":               {"deps": [],                                                              "cat": "solver",     "label": "SPOOLES"},
    "superlu-rvv":           {"deps": ["openblas-riscv64"],                                            "cat": "solver",     "label": "SuperLU"},
    "scotch-riscv64":        {"deps": [],                                                              "cat": "solver",     "label": "Scotch"},
    "petsc-rvv":             {"deps": ["openblas-riscv64", "lapack", "superlu-rvv", "scotch-riscv64"], "cat": "solver",     "label": "PETSc"},
    "sundials-rvv":          {"deps": ["openblas-riscv64", "lapack"],                                  "cat": "solver",     "label": "SUNDIALS"},
    "eigen":                 {"deps": [],                                                              "cat": "math",       "label": "Eigen"},
    "fftw3-rvv":             {"deps": [],                                                              "cat": "math",       "label": "FFTW3"},
    "gsl-riscv64":           {"deps": [],                                                              "cat": "math",       "label": "GSL"},
    "clhep-riscv64":         {"deps": [],                                                              "cat": "math",       "label": "CLHEP"},
    "libxc-riscv64":         {"deps": [],                                                              "cat": "math",       "label": "LibXC"},
    "zlib-riscv64":          {"deps": [],                                                              "cat": "io",         "label": "zlib"},
    "lz4-riscv64":           {"deps": [],                                                              "cat": "io",         "label": "LZ4"},
    "libdeflate-riscv64":    {"deps": [],                                                              "cat": "io",         "label": "libdeflate"},
    "xxhash-riscv64":        {"deps": [],                                                              "cat": "io",         "label": "xxHash"},
    "libb2-riscv64":         {"deps": [],                                                              "cat": "io",         "label": "libb2"},
    "libmd-riscv64":         {"deps": [],                                                              "cat": "io",         "label": "libmd"},
    "libbsd-riscv64":        {"deps": ["libmd-riscv64"],                                               "cat": "io",         "label": "libbsd"},
    "libuuid-riscv64":       {"deps": [],                                                              "cat": "io",         "label": "libuuid"},
    "libyaml-riscv64":       {"deps": [],                                                              "cat": "io",         "label": "libyaml"},
    "libsigsegv-riscv64":    {"deps": [],                                                              "cat": "io",         "label": "libsigsegv"},
    "pcre2-riscv64":         {"deps": [],                                                              "cat": "io",         "label": "PCRE2"},
    "libpng-riscv64":        {"deps": ["zlib-riscv64"],                                                "cat": "io",         "label": "libpng"},
    "libarchive-riscv64":    {"deps": ["zlib-riscv64", "lz4-riscv64"],                                 "cat": "io",         "label": "libarchive"},
    "c-blosc-riscv64":       {"deps": ["lz4-riscv64", "zlib-riscv64"],                                 "cat": "io",         "label": "c-Blosc"},
    "hdf5-rvv":              {"deps": ["zlib-riscv64"],                                                "cat": "io",         "label": "HDF5"},
    "stream-rvv":            {"deps": ["openblas-riscv64"],                                            "cat": "sim",        "label": "STREAM"},
    "gmsh":                  {"deps": ["eigen", "fftw3-rvv"],                                          "cat": "sim",        "label": "Gmsh"},
    "calculix-ccx":          {"deps": ["spooles", "arpack-ng-rvv", "openblas-riscv64"],                "cat": "sim",        "label": "CalculiX"},
    "oofem":                 {"deps": ["spooles", "petsc-rvv"],                                        "cat": "sim",        "label": "OOFEM"},
    "getdp":                 {"deps": ["petsc-rvv", "gmsh"],                                           "cat": "sim",        "label": "GetDP"},
    "elmer":                 {"deps": ["openblas-riscv64", "lapack", "scotch-riscv64", "hdf5-rvv"],    "cat": "sim",        "label": "Elmer"},
    "gromacs-rvv":           {"deps": ["openblas-riscv64", "fftw3-rvv", "hdf5-rvv"],                   "cat": "sim",        "label": "GROMACS"},
    "lammps-riscv64":        {"deps": ["openblas-riscv64", "fftw3-rvv"],                               "cat": "sim",        "label": "LAMMPS"},
    "lammps-rvv":            {"deps": ["openblas-rvv", "fftw3-rvv"],                                   "cat": "sim",        "label": "LAMMPS RVV"},
    "openmm-riscv64":        {"deps": ["openblas-riscv64", "fftw3-rvv"],                               "cat": "sim",        "label": "OpenMM"},
    "opencv-riscv64":        {"deps": ["zlib-riscv64", "libpng-riscv64"],                              "cat": "ml",         "label": "OpenCV"},
    "tensorflow-lite-rvv":   {"deps": ["openblas-rvv", "eigen"],                                       "cat": "ml",         "label": "TFLite"},
}

CAT_COLOR = {
    "foundation": "#1D9E75",
    "math":       "#7F77DD",
    "solver":     "#D85A30",
    "io":         "#888780",
    "sim":        "#378ADD",
    "ml":         "#D4537E",
}
CAT_LABEL = {
    "foundation": "Foundation",
    "math":       "Math / Linear Algebra",
    "solver":     "Solvers",
    "io":         "I/O & Compression",
    "sim":        "Simulation",
    "ml":         "ML / Vision",
}

def run(cmd):
    # Run shell command with 30s timeout; returns (returncode, stdout, stderr)
    try:
        r = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=30)
        return r.returncode, r.stdout.strip(), r.stderr.strip()
    except subprocess.TimeoutExpired:
        return -1, "", "TIMEOUT"

def find_debs():
    # Search debs/, releases/, and repo root; deduplicate by filename
    debs = []
    for d in [DEBS_DIR, REPO_ROOT/"releases", REPO_ROOT]:
        if d.exists():
            debs.extend(d.glob("*.deb"))
    seen, unique = set(), []
    for d in debs:
        if d.name not in seen:
            seen.add(d.name)
            unique.append(d)
    return sorted(unique)

def verify_arch(deb):
    # Check Architecture field in .deb control; must be riscv64
    rc, out, err = run(f"dpkg-deb -f '{deb}' Architecture")
    if rc != 0: return False, f"dpkg-deb error: {err}"
    return (True, "riscv64") if out.strip() == "riscv64" else (False, f"wrong: {out.strip()}")

def verify_elf(deb):
    # Extract .deb and inspect ELF binaries for RISC-V architecture
    tmp = tempfile.mkdtemp()
    try:
        rc, _, err = run(f"dpkg-deb -x '{deb}' '{tmp}'")
        if rc != 0: return False, f"extract failed: {err}"
        rc2, out2, _ = run(f"find '{tmp}' -type f | xargs file 2>/dev/null | grep ELF")
        if not out2:
            _, out3, _ = run(f"find '{tmp}' -type f | head -3")
            # No ELF = header-only package (e.g. eigen, lapack dev headers)
            return (True, "header-only") if out3 else (False, "empty package")
        lines = out2.splitlines()
        rv = sum(1 for l in lines if "RISC-V" in l)
        return (True, f"{rv}/{len(lines)} RISC-V ELF") if rv > 0 else (False, f"x86 ELF found")
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

def audit(deb, check_elf=True):
    # Parse name/version from filename convention: <name>_<version>_<arch>.deb
    parts = deb.stem.split("_")
    name = "_".join(parts[:-2]) if len(parts) >= 3 else deb.stem
    version = parts[-2] if len(parts) >= 3 else "unknown"
    r = {"file": deb.name, "name": name, "version": version,
         "size_kb": round(deb.stat().st_size/1024, 1), "status": None, "reason": None}
    ok, msg = verify_arch(deb)
    r["arch"] = msg
    if not ok:
        r["status"] = "FAIL"; r["reason"] = msg; return r
    if check_elf and r["size_kb"] < 100*1024:
        ok2, msg2 = verify_elf(deb)
        r["elf"] = msg2
        if not ok2:
            r["status"] = "FAIL"; r["reason"] = msg2; return r
    else:
        r["elf"] = "SKIP"
    r["status"] = "PASS"
    return r

def generate_html(results):
    # Build node/edge lists from DEPS + audit results for interactive graph
    audit_map = {r["name"]: r for r in results}

    nodes, edges = [], []
    for pkg, meta in DEPS.items():
        ar = audit_map.get(pkg)
        if not ar:
            for k in audit_map:
                if k.startswith(pkg) or pkg.startswith(k):
                    ar = audit_map[k]; break
        status = ar["status"] if ar else "UNKNOWN"
        elf    = ar.get("elf", "") if ar else ""
        ver    = ar["version"] if ar else ""
        size   = ar["size_kb"] if ar else 0
        nodes.append({"id": pkg, "label": meta["label"], "cat": meta["cat"],
                      "color": CAT_COLOR[meta["cat"]], "status": status,
                      "elf": elf, "ver": ver, "size_kb": size})
        for dep in meta["deps"]:
            edges.append({"from": dep, "to": pkg})

    nodes_json = json.dumps(nodes)
    edges_json = json.dumps(edges)
    cat_legend = json.dumps([{"cat": c, "label": CAT_LABEL[c], "color": CAT_COLOR[c]} for c in CAT_COLOR])
    total  = len(results)
    passed = sum(1 for r in results if r["status"] == "PASS")
    failed = total - passed
    ts     = datetime.now().strftime("%Y-%m-%d %H:%M")

    return f"""<!DOCTYPE html>
<html lang="en"><head><meta charset="UTF-8">
<title>HPC riscv64 Dependency Graph</title>
<script src="https://cdnjs.cloudflare.com/ajax/libs/vis/4.21.0/vis.min.js"></script>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/vis/4.21.0/vis.min.css"/>
<style>
*{{box-sizing:border-box;margin:0;padding:0;font-family:system-ui,sans-serif}}
body{{background:#0f1117;color:#e2e8f0;height:100vh;display:flex;flex-direction:column}}
header{{padding:1rem 1.5rem;border-bottom:1px solid #1e2530;flex-shrink:0}}
header h1{{font-size:1.1rem;font-weight:600;color:#f1f5f9}}
header p{{font-size:.78rem;color:#64748b;margin-top:.2rem}}
.stats{{display:flex;gap:.75rem;padding:.75rem 1.5rem;background:#0d1117;border-bottom:1px solid #1e2530;flex-shrink:0}}
.stat{{background:#131720;border:1px solid #1e2530;border-radius:6px;padding:.4rem 1rem}}
.stat .val{{font-size:1.2rem;font-weight:700}}
.stat .lbl{{font-size:.68rem;color:#64748b;text-transform:uppercase;letter-spacing:.05em}}
.pass{{color:#22c55e}}.fail{{color:#ef4444}}.tot{{color:#60a5fa}}
.main{{display:flex;flex:1;overflow:hidden}}
#graph{{flex:1}}
#sidebar{{width:260px;background:#0d1117;border-left:1px solid #1e2530;overflow-y:auto;padding:.75rem;flex-shrink:0}}
#sidebar h2{{font-size:.72rem;text-transform:uppercase;letter-spacing:.08em;color:#475569;margin-bottom:.5rem}}
.filter-row{{display:flex;flex-wrap:wrap;gap:.3rem;margin-bottom:.75rem}}
.fbtn{{background:#131720;border:1px solid #1e2530;border-radius:5px;padding:.25rem .6rem;font-size:.72rem;color:#94a3b8;cursor:pointer}}
.fbtn.active,.fbtn:hover{{border-color:#3b82f6;color:#93c5fd;background:#1e293b}}
.legend-item{{display:flex;align-items:center;gap:.4rem;margin:.25rem 0;font-size:.78rem;color:#94a3b8}}
.dot{{width:9px;height:9px;border-radius:50%;flex-shrink:0}}
#pkg-detail{{margin-top:1rem;display:none;background:#131720;border:1px solid #1e2530;border-radius:6px;padding:.75rem}}
#pkg-detail h3{{font-size:.85rem;font-weight:600;color:#f1f5f9;margin-bottom:.5rem}}
.row{{display:flex;justify-content:space-between;font-size:.75rem;padding:.25rem 0;border-bottom:1px solid #1a2035}}
.row .k{{color:#475569}}.row .v{{color:#cbd5e1;font-weight:500}}
.badge{{display:inline-block;padding:1px 7px;border-radius:3px;font-size:.7rem;font-weight:600}}
.badge-pass{{background:#14532d;color:#4ade80}}.badge-fail{{background:#450a0a;color:#f87171}}
</style></head><body>
<header>
  <h1>HPC riscv64 — Dependency Graph</h1>
  <p>Cross-compiled packages · Architecture: riscv64 · {ts}</p>
</header>
<div class="stats">
  <div class="stat"><div class="val tot">{total}</div><div class="lbl">Total</div></div>
  <div class="stat"><div class="val pass">{passed}</div><div class="lbl">Pass</div></div>
  <div class="stat"><div class="val fail">{failed}</div><div class="lbl">Fail</div></div>
</div>
<div class="main">
  <div id="graph"></div>
  <div id="sidebar">
    <h2>Filter by category</h2>
    <div class="filter-row" id="filters"></div>
    <h2>Legend</h2>
    <div id="legend"></div>
    <div id="pkg-detail">
      <h3 id="d-name"></h3>
      <div class="row"><span class="k">Version</span><span class="v" id="d-ver"></span></div>
      <div class="row"><span class="k">Status</span><span class="v" id="d-status"></span></div>
      <div class="row"><span class="k">ELF</span><span class="v" id="d-elf"></span></div>
      <div class="row"><span class="k">Size</span><span class="v" id="d-size"></span></div>
      <div class="row"><span class="k">Category</span><span class="v" id="d-cat"></span></div>
    </div>
  </div>
</div>
<script>
const ND={nodes_json};
const ED={edges_json};
const LEG={cat_legend};
let af=null;
function bn(f){{return ND.filter(n=>!f||n.cat===f).map(n=>({{
  id:n.id,label:n.label,
  color:{{background:n.color+'33',border:n.color,highlight:{{background:n.color+'66',border:n.color}}}},
  font:{{color:'#e2e8f0',size:12,face:'system-ui'}},
  borderWidth:n.status==='PASS'?2:3,borderDashes:n.status!=='PASS',
  shape:n.cat==='foundation'?'diamond':'box',margin:6,_meta:n
}}));}}
function be(f){{const ids=new Set(bn(f).map(n=>n.id));
return ED.filter(e=>ids.has(e.from)&&ids.has(e.to)).map(e=>({{
  from:e.from,to:e.to,arrows:'to',
  color:{{color:'#1e2d40',highlight:'#3b82f6'}},
  smooth:{{type:'cubicBezier',forceDirection:'vertical',roundness:0.4}}
}}));}}
const nodes=new vis.DataSet(bn(null));
const edges=new vis.DataSet(be(null));
const net=new vis.Network(document.getElementById('graph'),{{nodes,edges}},{{
  layout:{{hierarchical:{{direction:'UD',sortMethod:'directed',levelSeparation:80,nodeSpacing:120}}}},
  physics:false,interaction:{{hover:true,tooltipDelay:80}}
}});
net.on('click',p=>{{
  if(!p.nodes.length){{document.getElementById('pkg-detail').style.display='none';return;}}
  const n=ND.find(x=>x.id===p.nodes[0]);if(!n)return;
  document.getElementById('pkg-detail').style.display='block';
  document.getElementById('d-name').textContent=n.label;
  document.getElementById('d-ver').textContent=n.ver||'—';
  document.getElementById('d-status').innerHTML=`<span class="badge badge-${{n.status.toLowerCase()}}">${{n.status}}</span>`;
  document.getElementById('d-elf').textContent=n.elf||'—';
  document.getElementById('d-size').textContent=n.size_kb?n.size_kb+' KB':'—';
  document.getElementById('d-cat').textContent=LEG.find(l=>l.cat===n.cat)?.label||n.cat;
}});
const leg=document.getElementById('legend');
const fil=document.getElementById('filters');
LEG.forEach(l=>{{
  leg.innerHTML+=`<div class="legend-item"><div class="dot" style="background:${{l.color}}"></div>${{l.label}}</div>`;
  const b=document.createElement('button');
  b.className='fbtn';b.textContent=l.label.split('/')[0].trim();
  b.onclick=()=>{{
    af=af===l.cat?null:l.cat;
    document.querySelectorAll('.fbtn').forEach(x=>x.classList.remove('active'));
    if(af)b.classList.add('active');
    nodes.clear();edges.clear();nodes.add(bn(af));edges.add(be(af));
  }};
  fil.appendChild(b);
}});
</script></body></html>"""

def main():
    p = argparse.ArgumentParser()
    p.add_argument("--all", action="store_true")        # audit all found debs
    p.add_argument("--no-elf", action="store_true")     # skip ELF check (arch only)
    p.add_argument("--debs-dir")                        # override default debs/ path
    p.add_argument("--no-graph", action="store_true")   # skip HTML graph generation
    args = p.parse_args()
    global DEBS_DIR
    if args.debs_dir: DEBS_DIR = Path(args.debs_dir)
    debs = find_debs()
    if not debs:
        print(f"[!] No .deb files found in {DEBS_DIR}"); return 1
    print(f"[*] Found {len(debs)} .deb files\n")
    results, passed, failed = [], 0, 0
    for i, deb in enumerate(debs, 1):
        print(f"[{i:02d}/{len(debs)}] {deb.name} ...", end=" ", flush=True)
        r = audit(deb, check_elf=not args.no_elf)
        results.append(r)
        if r["status"] == "PASS":
            passed += 1; print(f"PASS  {r.get('elf','')}")
        else:
            failed += 1; print(f"FAIL  {r['reason']}")
    print(f"\n{'='*50}")
    print(f"  TOTAL: {len(debs)}  PASS: {passed}  FAIL: {failed}")
    print(f"{'='*50}\n")
    report = {"generated": datetime.now().isoformat(),
              "summary": {"total": len(debs), "passed": passed, "failed": failed},
              "packages": results}
    with open("audit_report_v2.json", "w") as f:
        json.dump(report, f, indent=2)
    print("[+] Saved: audit_report_v2.json")
    if not args.no_graph:
        html = generate_html(results)
        with open("hpc_graph.html", "w") as f:
            f.write(html)
        print("[+] Saved: hpc_graph.html  (open in browser)")

if __name__ == "__main__":
    main()
