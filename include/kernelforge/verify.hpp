#pragma once
#include <cstddef>

//Compares two FP32 buffers using absolute and relative tolerances.
//Returns false when any element differs beyond both tolerances.
bool buffers_nearly_equal(
    const float* expected,
    const float* actual,
    std::size_t count,
    float absolute_tolerance,
    float relative_tolerance
);