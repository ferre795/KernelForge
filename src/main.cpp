#include <iostream>
#include <array>
#include "kernelforge/gemm.hpp"
#include "kernelforge/verify.hpp"
#include "kernelforge/matrix_utils.hpp"

int main() {
    const std::array<float, 4> a1 = {1, 2, 3, 4};
    const std::array<float, 4> b1 = {5, 6, 7, 8};
    std::array<float, 4> c1;

    const std::array<float, 8> a2 = {1, 2, 3, 4, 5, 6, 7, 8};
    const std::array<float, 12> b2 = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::array<float, 6> c2;

    std::cout << "KernelForge initialized." << std::endl;

    reordered_gemm(a1.data(), b1.data(), c1.data(), 2, 2, 2);
    reordered_gemm(a2.data(), b2.data(), c2.data(), 2, 3, 4); 

    const std::array<float, 4> c1_expected = {19, 22, 43, 50};
    const std::array<float, 6> c2_expected = {150, 160, 170, 366, 392, 418};

    constexpr float absolute_tolerance = 1e-5F;
    constexpr float relative_tolerance = 1e-5F;

    const bool res1 = buffers_nearly_equal(c1_expected.data(), c1.data(), c1.size(), absolute_tolerance, relative_tolerance);
    const bool res2 = buffers_nearly_equal(c2_expected.data(), c2.data(), c2.size(), absolute_tolerance, relative_tolerance);

    if(res1 && res2) {
        std::cout << "All test cases passed.\n"; 
        return 0; 
    }

    std::cerr << "One or more test cases failed.\n"; 
    

    return 1; 

    /*
    //test seed generator
    std::vector<float> mat1 = make_random_matrix(2, 3, 10329); 
    std::vector<float> mat2 = make_random_matrix(2, 3, 10329); 
    std::vector<float> mat3 = make_random_matrix(2, 3, 98127); 

    if(mat1 == mat2) {
        std::cout << "Matrix 1 and matrix 2 are the same." <<std::endl; 
    }

    if(mat1 != mat3) {
        std::cout << "Matrix 1 and matrix 3 are different." << std::endl; 
    }
    */
}