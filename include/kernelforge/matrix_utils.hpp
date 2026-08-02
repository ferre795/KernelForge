#pragma once
#include <vector>

//Creates a contiguous row-major FP32 matrix filled with deterministic random values.
std::vector<float> make_random_matrix(
    std::size_t rows,
    std::size_t columns,
    std::uint32_t seed
);