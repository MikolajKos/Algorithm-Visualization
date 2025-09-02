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

void Algorithm::insertionSort(std::vector<float>& nums, Callback onChange) {
	for (size_t i = 1; i < nums.size() - 1; ++i) {
		size_t j = i;
		while (j > 0 && nums[j - 1] > nums[j]) {
			std::swap(nums[j], nums[j - 1]);
			onChange(nums);
			j--;
		}
	}
}

void Algorithm::selectionSort(std::vector<float>& nums, Callback onChange) {
	for (size_t i = 0; i < nums.size(); ++i) {
		size_t min_index = i;

		for (size_t j = i + 1; j < nums.size(); ++j) {
			if (nums[j] < nums[min_index]) {
				min_index = j;
			}
		}

		if (i != min_index) {
			std::swap(nums[i], nums[min_index]);
			onChange(nums);
		}
	}
}

void Algorithm::quicksort(std::vector<float>& nums, Callback onChange) {
	quicksort_recursion(nums, 0, nums.size() - 1, onChange);
}

void Algorithm::quicksort_recursion(std::vector<float>& nums, int low, int high, Callback onChange) {
	if (low < high) {
		int pivot_index = partition(nums, low, high, onChange);

		quicksort_recursion(nums, low, pivot_index - 1, onChange);
		quicksort_recursion(nums, pivot_index + 1, high, onChange);
	}
}

int Algorithm::partition(std::vector<float>& nums, int low, int high, Callback onChange) {
	float pivot_value = nums[high];

	int i = low;
	for (int j = low; j < high; ++j) {
		if (nums[j] <= pivot_value) {
			std::swap(nums[i], nums[j]);
			++i;

			onChange(nums);
		}
	}
	std::swap(nums[i], nums[high]);
	onChange(nums);

	return i;
}