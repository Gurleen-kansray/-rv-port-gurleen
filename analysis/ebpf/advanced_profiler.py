#!/usr/bin/env python3
import subprocess
import json
import sys
from datetime import datetime
from collections import defaultdict

class SyscallProfiler:
    def __init__(self, binary_path, duration=30):
        self.binary_path = binary_path
        self.duration = duration
        self.results = {
            "binary": binary_path,
            "duration": duration,
            "timestamp": datetime.now().isoformat(),
            "syscalls": {},
            "summary": {}
        }
    
    def run_strace(self):
        """Run binary under strace."""
        print(f"[*] Profiling {self.binary_path}...")
        
        try:
            cmd = f"timeout {self.duration} strace -c -e trace=all {self.binary_path} 2>&1"
            result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
            return result.stderr
        except:
            return ""
    
    def parse_output(self, output):
        """Parse strace output."""
        lines = output.split('\n')
        
        for line in lines:
            parts = line.split()
            if len(parts) >= 6 and parts[-1] not in ['syscall', 'seconds', 'calls']:
                try:
                    pct = float(parts[0])
                    seconds = float(parts[1])
                    usecs = int(parts[2])
                    calls = int(parts[3])
                    syscall = parts[-1]
                    
                    self.results["syscalls"][syscall] = {
                        "calls": calls,
                        "total_time_us": seconds * 1e6,
                        "avg_latency_us": usecs,
                        "percent_time": pct
                    }
                except:
                    pass
    
    def generate_summary(self):
        """Create summary."""
        if not self.results["syscalls"]:
            return
        
        total_calls = sum(s["calls"] for s in self.results["syscalls"].values())
        top_by_count = sorted(self.results["syscalls"].items(), 
                             key=lambda x: x[1]["calls"], reverse=True)[:10]
        
        self.results["summary"] = {
            "total_syscalls": total_calls,
            "unique_syscalls": len(self.results["syscalls"]),
            "top_by_count": [(name, data["calls"]) for name, data in top_by_count]
        }
    
    def save_results(self, output_file):
        """Save JSON results."""
        with open(output_file, "w") as f:
            json.dump(self.results, f, indent=2)
        print(f"[+] Saved: {output_file}")
    
    def run(self, output_file):
        """Execute full profiling."""
        output = self.run_strace()
        self.parse_output(output)
        self.generate_summary()
        self.save_results(output_file)
        return self.results

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: advanced_profiler.py <binary> [duration]")
        sys.exit(1)
    
    binary = sys.argv[1]
    duration = int(sys.argv[2]) if len(sys.argv) > 2 else 10
    
    profiler = SyscallProfiler(binary, duration)
    results = profiler.run(f"{binary.split('/')[-1]}_profile.json")
    
    print("\n=== PROFILE SUMMARY ===")
    print(f"Total syscalls: {results['summary'].get('total_syscalls', 0):,}")
    print(f"Unique syscalls: {results['summary'].get('unique_syscalls', 0)}")
    print("\nTop 5 syscalls by count:")
    for name, count in results['summary'].get('top_by_count', [])[:5]:
        print(f"  {name}: {count:,}")
