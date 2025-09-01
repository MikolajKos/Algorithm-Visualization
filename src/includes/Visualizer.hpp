#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>

class Visualizer {
	unsigned int height, width;
	float barWidth;
	float noBars;
	sf::RenderWindow window;
public:
	Visualizer() :
		window(sf::VideoMode({ 800, 600 }), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close),
		height(600), width(800), noBars(50), barWidth(800 / 50.0f) 
	{
		window.setFramerateLimit(60);
	};

	Visualizer(unsigned int w, unsigned int h, float nbars) :
		window(sf::VideoMode({ w, h }), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close),
		height(h), width(w), noBars(nbars), barWidth(w / nbars) 
	{
		window.setFramerateLimit(60);
	};

	// Methods
	bool isOpen();
	void handleEvents();
	void draw(const std::vector<float> nums);
};

#endif