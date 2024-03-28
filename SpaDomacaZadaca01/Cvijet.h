#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
	sf::Time t;
	float scale = 1.f;
	float scaleSpeed = .5f;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

