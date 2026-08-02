#include "kernelforge/matrix_utils.hpp"
#include <random> 

std::vector<float> make_random_matrix(std::size_t rows, std::size_t columns, std::uint32_t seed) {
    std::vector<float> matrix(rows * columns);

    std::mt19937 gen(seed); 
    std::uniform_real_distribution<float> distrib(-1.0F, 1.0F);

    for(std::size_t i = 0; i < rows*columns; i++) {
        matrix[i] = distrib(gen); 
    }

    return matrix; 
}