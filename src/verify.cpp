#include "kernelforge/verify.hpp"
#include <iostream> 

bool buffers_nearly_equal(const float* expected, const float* actual, std::size_t count, float absolute_tolerance, float relative_tolerance) {
    for(std::size_t i = 0; i < count; i++) {
        float absolute_error = abs(expected[i] - actual[i]); 
        float allowed_error = absolute_tolerance + relative_tolerance * abs(expected[i]); 

        if(absolute_error > allowed_error) {
            return false; 
        }
    }
    return true; 
}