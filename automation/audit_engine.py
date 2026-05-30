#!/usr/bin/env python3
import subprocess
import json
import os
from datetime import datetime
from pathlib import Path

class AuditEngine:
    def __init__(self, work_dir="/mnt/d/rv-port-work/-rv-port-gurleen"):
        self.work_dir = work_dir
        
    def build_package(self, name, git_url, branch="main"):
        print(f"\n=== Building {name} ===")
        
        build_dir = f"/tmp/build-{name}"
        
        try:
            # Clean previous build
            subprocess.run(["rm", "-rf", build_dir])
            
            # Clone
            print(f"[1/4] Cloning...")
            subprocess.run(["git", "clone", "--depth", "1", "--branch", branch, git_url, build_dir], 
                          check=True, capture_output=True)
            
            os.chdir(build_dir)
            
            # Check for autotools (GSL uses this)
            if (Path(build_dir) / "configure").exists():
                print("[2/4] Configuring with autotools...")
                subprocess.run(["./configure", "--host=riscv64-linux-gnu", "--prefix=/usr"], 
                              check=True)
                print("[3/4] Building...")
                subprocess.run(["make", "-j4"], check=True)
                print("[4/4] Installing...")
                subprocess.run(["make", "install", f"DESTDIR=/tmp/{name}-install"], check=True)
                print(f"✅ {name} built successfully")
                return True
                
            elif (Path(build_dir) / "CMakeLists.txt").exists():
                print("[2/4] Configuring with CMake...")
                toolchain = self.work_dir + "/riscv64-linux-gnu.cmake"
                subprocess.run(["cmake", "-B", "build", f"-DCMAKE_TOOLCHAIN_FILE={toolchain}"], 
                              check=True)
                print("[3/4] Building...")
                subprocess.run(["cmake", "--build", "build", "-j4"], check=True)
                print("[4/4] Installing...")
                subprocess.run(["cmake", "--install", "build", "--prefix", f"/tmp/{name}-install"], 
                              check=True)
                print(f"✅ {name} built successfully")
                return True
            else:
                print(f"❌ No known build system")
                return False
                
        except Exception as e:
            print(f"❌ Failed: {e}")
            return False
        finally:
            os.chdir(self.work_dir)
            subprocess.run(["rm", "-rf", build_dir])

if __name__ == "__main__":
    engine = AuditEngine()
    
    # Test with GSL (autotools)
    result = engine.build_package("gsl", "https://github.com/ampl/gsl.git", "master")
    print(f"\nResult: {result}")
