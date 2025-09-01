#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <functional>
#include <vector>

using Callback = std::function<void(const std::vector<float>&)>;

class Algorithm {
public:
    void bubbleSort(std::vector<float>& nums, Callback onChange);
};

#endif