#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <iostream>
#include "includes/Visualizer.hpp"
#include "includes/Algorithm.hpp"

#define WIDTH 800.0f
#define HEIGHT 600.0f
#define BARS_COUNT 500

int main()
{
	std::cout << "Choose algorithm:\n";
	std::cout << "1. Bubble Sort\n";
	std::cout << "2. Insertion Sort\n";
	std::cout << "3. Selection Sort\n";
	std::cout << "4. Quick Sort\n";
	std::cout << "5. Heap Sort\n";
	std::cout << "0. Exit\n\n";

	int selectedOption = 0;
	std::cin >> selectedOption;

	Visualizer vis(WIDTH, HEIGHT, BARS_COUNT);

	// Data
	std::vector<float> nums(BARS_COUNT);
	float dt = HEIGHT / BARS_COUNT;

	// Fill vector
	for (size_t i = 0; i < nums.capacity(); ++i)
		nums[i] = (i + 1) * dt;

	// Randomize data order
	std::random_device r;
	std::mt19937 g(r());
	std::shuffle(nums.begin(), nums.end(), g);

	vis.draw(nums);

	auto callback = [&](const std::vector<float>& arr) {
		vis.handleEvents();
		
		static int counter = 0;

		if (++counter % 500 == 0) {
			vis.draw(arr);
		}
	};

	Algorithm alg;

	switch (selectedOption)
	{
	case 1:
		alg.bubbleSort(nums, callback);
		break;
	case 0:
		return 0;
	default:
		break;
	}

	while (vis.isOpen())
	{
		vis.handleEvents();
		vis.draw(nums);
	}

	return 0;
}
