cmake_minimum_required(VERSION 3.20)

project(KernelForge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(kernelforge
    src/main.cpp
    src/reference_gemm.cpp
    src/verify.cpp
    src/matrix_utils.cpp
)

target_include_directories(kernelforge PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_options(kernelforge PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
)