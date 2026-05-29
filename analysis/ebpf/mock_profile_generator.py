#!/usr/bin/env python3
import json
from datetime import datetime

# Mock profiles for GetDP, OOFEM, ARPACK, LAMMPS, PETSc
profiles = {
    "GetDP": {
        "total_syscalls": 7579,
        "top_syscalls": {"openat": 332, "close": 285, "read": 198, "futex": 156},
        "sync_overhead": 156,
        "io_overhead": 815,
        "hardware_speedup": "1.5x"
    },
    "OOFEM": {
        "total_syscalls": 5234,
        "top_syscalls": {"openat": 570, "mmap": 211, "futex": 107, "read": 89},
        "sync_overhead": 107,
        "io_overhead": 781,
        "hardware_speedup": "5x"
    },
    "ARPACK-ng": {
        "total_syscalls": 1243,
        "top_syscalls": {"sched_yield": 1156, "futex": 87},
        "sync_overhead": 1243,
        "io_overhead": 0,
        "hardware_speedup": "50x"
    },
    "LAMMPS": {
        "total_syscalls": 234567,
        "top_syscalls": {"futex": 98234, "epoll_wait": 45123, "poll": 67890, "sched_yield": 12340},
        "sync_overhead": 110247,
        "io_overhead": 2341,
        "hardware_speedup": "25x"
    },
    "PETSc": {
        "total_syscalls": 1845234,
        "top_syscalls": {"futex": 1456789, "poll": 234567, "sched_yield": 78945},
        "sync_overhead": 1456789,
        "io_overhead": 156,
        "hardware_speedup": "75x"
    }
}

for name, data in profiles.items():
    result = {
        "binary": name,
        "timestamp": datetime.now().isoformat(),
        "summary": data,
        "analysis": {
            "sync_dominated": data["sync_overhead"] > data["total_syscalls"] * 0.2,
            "io_bound": data["io_overhead"] > data["total_syscalls"] * 0.1,
            "hardware_prediction": f"QEMU: {data['total_syscalls']:,} syscalls -> Hardware: {data['total_syscalls']//10:,} (est. {data['hardware_speedup']})"
        }
    }
    
    with open(f"{name.lower()}_profile.json", "w") as f:
        json.dump(result, f, indent=2)
    
    print(f"[+] Created {name.lower()}_profile.json")

print("\n[+] All mock profiles created")
