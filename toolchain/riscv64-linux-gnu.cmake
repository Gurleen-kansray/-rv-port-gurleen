# RISC-V 64-bit Linux GNU Toolchain
# For cross-compiling HPC codes to riscv64

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv64)

# Specify the cross compiler
set(CMAKE_C_COMPILER riscv64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER riscv64-linux-gnu-g++)
set(CMAKE_Fortran_COMPILER riscv64-linux-gnu-gfortran)

# Where the target environment is located
set(CMAKE_FIND_ROOT_PATH /usr/riscv64-linux-gnu)

# Adjust the default behavior of the find commands
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# RISC-V specific flags
set(CMAKE_C_FLAGS "-march=rv64g -mabi=lp64d" CACHE STRING "C flags")
set(CMAKE_CXX_FLAGS "-march=rv64g -mabi=lp64d" CACHE STRING "C++ flags")
set(CMAKE_Fortran_FLAGS "-march=rv64g -mabi=lp64d -fallow-argument-mismatch -Wno-do-subscript" CACHE STRING "Fortran flags")

# Cross-compiling emulator for try_run
set(CMAKE_CROSSCOMPILING_EMULATOR qemu-riscv64-static)

# Disable try_run checks if they fail
set(CMAKE_CROSSCOMPILING TRUE)

message(STATUS "Using RISC-V 64-bit GNU cross-compilation toolchain")
