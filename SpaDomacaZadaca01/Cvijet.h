#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
	sf::Time t;
	bool maxSize;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

