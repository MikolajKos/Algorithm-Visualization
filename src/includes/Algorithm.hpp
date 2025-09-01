#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <functional>
#include <vector>

using Callback = std::function<void(const std::vector<float>&)>;

class Algorithm {
public:
    void bubbleSort(std::vector<float>& nums, Callback onChange);
    
    void quicksort(std::vector<float>& nums);
   
private:
    // Helper methods
    int quicksort_recursive(std::vector<float>& nums, int low, int high);
};

#endif