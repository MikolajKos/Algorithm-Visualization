#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <functional>
#include <vector>

using Callback = std::function<void(const std::vector<float>&)>;

class Algorithm {
public:
    void bubbleSort(std::vector<float>& nums, Callback onChange);
    void insertionSort(std::vector<float>& nums, Callback onChange);
    void selectionSort(std::vector<float>& nums, Callback onChange);
    void quicksort(std::vector<float>& nums, Callback onChange);
   
private:
    // Helper methods
    void quicksort_recursion(std::vector<float>& nums, int low, int high, Callback onChange);
    int partition(std::vector<float>& nums, int low, int high, Callback onChange);
};

#endif