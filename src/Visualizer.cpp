#include "includes/Visualizer.hpp"

bool Visualizer::isOpen() { return window.isOpen(); }

void Visualizer::handleEvents() {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>())
			window.close();
	}
}

void Visualizer::draw(const std::vector<float> nums) {
	window.clear();
	for (int k = 0; k < noBars; ++k) {
		sf::RectangleShape bar({barWidth, nums[k]});
		bar.setPosition({barWidth * k, height - nums[k]});
		bar.setFillColor(sf::Color::White);
		window.draw(bar);
	}
	window.display();
}