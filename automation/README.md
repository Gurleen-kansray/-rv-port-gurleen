# RISC-V HPC Automation Pipeline

Production automation for cross-compiling 50+ HPC codes to RISC-V.

## Quick Start
```bash
./automation/build_batch.sh
```

## Architecture
- **build_package.sh**: Single package with CMake/autotools/make fallback
- **build_batch.sh**: Orchestrates 50+ packages in parallel
- **logs/**: Build logs for debugging

## Features
✅ Automatic fallback strategies (CMake → autotools → make)
✅ Comprehensive logging
✅ Parallel builds
✅ Failure tracking

## Future Work (Week 3-5 Mentorship)
- Dependency resolution
- Smart retry logic
- Performance profiling
- Hardware validation
