# RISC-V cross-compilation toolchain file for CMake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv64)

# Compilers
set(CMAKE_C_COMPILER riscv64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER riscv64-linux-gnu-g++)

# Toolchain utilities
set(CMAKE_AR riscv64-linux-gnu-ar CACHE FILEPATH "Archiver")
set(CMAKE_LINKER riscv64-linux-gnu-ld CACHE FILEPATH "Linker")
set(CMAKE_NM riscv64-linux-gnu-nm CACHE FILEPATH "NM")
set(CMAKE_OBJCOPY riscv64-linux-gnu-objcopy CACHE FILEPATH "Objcopy")
set(CMAKE_OBJDUMP riscv64-linux-gnu-objdump CACHE FILEPATH "Objdump")
set(CMAKE_RANLIB riscv64-linux-gnu-ranlib CACHE FILEPATH "Ranlib")
set(CMAKE_STRIP riscv64-linux-gnu-strip CACHE FILEPATH "Strip")

# Compiler flags
set(CMAKE_C_FLAGS "-march=rv64gc" CACHE STRING "C flags")
set(CMAKE_CXX_FLAGS "-march=rv64gc" CACHE STRING "C++ flags")

# Find root path for libraries
set(CMAKE_FIND_ROOT_PATH /usr/riscv64-linux-gnu /usr/lib/riscv64-linux-gnu)

# Search policy
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Make program
set(CMAKE_MAKE_PROGRAM /usr/bin/make CACHE FILEPATH "Make program")
