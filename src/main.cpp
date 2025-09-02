#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <iostream>
#include "includes/Visualizer.hpp"
#include "includes/Algorithm.hpp"

#define WIDTH 1900.0f
#define HEIGHT 1200.0f
#define BARS_COUNT 500

int main()
{
	int selectedOption = -1;
	while (selectedOption != 0) {
		std::cout << "Choose algorithm:\n";
		std::cout << "1. Bubble Sort\n";
		std::cout << "2. Insertion Sort\n";
		std::cout << "3. Selection Sort\n";
		std::cout << "4. Quick Sort\n";
		//std::cout << "5. Heap Sort\n";
		std::cout << "0. Exit\n";

		std::cout << "Enter number (0-4): ";
		std::cin >> selectedOption;
		std::cout << "\n";

		if (selectedOption == 0)
			break;

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

		//Initial draw
		vis.draw(nums);

		auto callback = [&](const std::vector<float>& arr) {
			if (vis.isOpen()) {
				vis.handleEvents();

				static int counter = 0;

				// Drawing every hundredth swap action for greater faster visualization
				if (++counter % 100 == 0) {
					vis.draw(arr);
				}
			}
		};

		Algorithm alg;

		switch (selectedOption)
		{
		case 1:
			alg.bubbleSort(nums, callback);
			break;
		case 2:
			alg.insertionSort(nums, callback);
			break;
		case 3:
			alg.selectionSort(nums, callback);
			break;
		case 4:
			alg.quicksort(nums, callback);
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

	}

	return 0;
}
