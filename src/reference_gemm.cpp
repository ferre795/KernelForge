#include "kernelforge/gemm.hpp"
#include <iostream> 

//A is M×K, B is K×N, and C is M×N.
void reference_gemm(const float* a, const float* b, float* c, std::size_t m, std::size_t n, std::size_t k) { 
    for(std::size_t i = 0; i < m; i++) {
        for(std::size_t j = 0; j < n; j++) {
            float sum = 0.0f;
            for(std::size_t p = 0; p < k; p++) {
                sum += a[i*k + p] * b[p*n + j]; 
            } 
            c[i*n + j] = sum; 
        }
    }
}

//A is M×K, B is K×N, and C is M×N.
void reordered_gemm(const float* a, const float* b, float* c, std::size_t m, std::size_t n, std::size_t k) {
    std::fill(c, c + m * n, 0.0F);

    for(std::size_t i = 0; i < m; i++) {
        for(std::size_t p = 0; p < k; p++) {
            float factor = a[i*k + p]; //i is the row, p is the column we're looking at
            for(std::size_t j = 0; j < n; j++) {
                c[i*n + j] += factor * b[p*n + j]; //row i of c, row p of b
            }
        }
    }
}