#pragma once
#include <cstddef>

//Computes C = A × B for row-major FP32 matrices. A is M×K, B is K×N, and C is M×N. 
void reference_gemm(
    const float* a,
    const float* b,
    float* c,
    std::size_t m,
    std::size_t n,
    std::size_t k
);

//Computes row-major FP32 GEMM using the i-p-j loop ordering.
void reordered_gemm(
    const float* a,
    const float* b,
    float* c,
    std::size_t m,
    std::size_t n,
    std::size_t k
);  