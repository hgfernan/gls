cmake_minimum_required(VERSION 3.10)
project(GLSPeriodogramProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(py_emulation
    py_emulation.cpp
    vec_operator.cpp
    vec_stats.cpp
    tiny_str.cpp
    arange.cpp
)

# 1. Base flags applied to ALL builds (Warnings)
target_compile_options(py_emulation PRIVATE -W -Wall -Wextra -Wpedantic)

# 2. DEBUG flags (-g for symbols, -O0 to disable optimization)
target_compile_options(py_emulation PRIVATE
    $<$<CONFIG:Debug>:-g -O0>
)

# 3. RELEASE flags (-O2 or -O3 for max speed, -DNDEBUG to strip asserts)
target_compile_options(py_emulation PRIVATE
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
)
