#include "includes/Algorithm.hpp"

void Algorithm::bubbleSort(std::vector<float>& nums, Callback onChange) {
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 0; j < nums.size() - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
            onChange(nums);
        }
    }
}

void quicksort(std::vector<float>& nums) {
    
}

int quicksort_recursive(std::vector<float>& nums, int low, int high) {
    if (low < high) {

    }
}