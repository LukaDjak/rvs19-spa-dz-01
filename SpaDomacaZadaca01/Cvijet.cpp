#include "Cvijet.h"
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	t = frameClock.restart();
}

void Cvijet::draw()
{
	//blue sky background
	sf::RectangleShape sky(sf::Vector2f(800, 600));
	sky.setFillColor(sf::Color(153, 228, 255));
	window->draw(sky);

	//the upper green part of the cvijet
	sf::RectangleShape upperLine(sf::Vector2f(10.f, 200.f));
	upperLine.setFillColor(sf::Color(44, 150, 59));
	upperLine.setPosition(100.f, 150.f);
	upperLine.rotate(-10);
	window->draw(upperLine);

	//the lower  green part of the cvijet
	sf::RectangleShape lowerLine(sf::Vector2f(10.f, 150.f));
	lowerLine.setFillColor(sf::Color(44, 150, 59));
	lowerLine.setPosition(135.f, 343.f);
	lowerLine.rotate(10);
	window->draw(lowerLine);

	//the leaf
	sf::ConvexShape leaf;
	leaf.setPointCount(5);
	leaf.setPoint(0, sf::Vector2f(140, 340));
	leaf.setPoint(1, sf::Vector2f(200, 310));
	leaf.setPoint(2, sf::Vector2f(230, 320));
	leaf.setPoint(3, sf::Vector2f(250, 350));
	leaf.setPoint(4, sf::Vector2f(190, 360));
	leaf.setFillColor(sf::Color(45, 128, 13));
	window->draw(leaf);

	//red circles
	for (int i = 0; i < 5; i++)
	{
		sf::CircleShape shape(30.f);
		shape.setFillColor(sf::Color(255, 0, 0));
		shape.setPosition(100, 100);
		shape.rotate((i + 1) * 72.f);
		window->draw(shape);
	}

	//yellow circle
	sf::CircleShape shape(35.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setPosition(65.f, 65.f);
	window->draw(shape);

	//ground
	sf::ConvexShape ground;
	ground.setPointCount(4);
	ground.setPoint(0, sf::Vector2f(0, 450));
	ground.setPoint(1, sf::Vector2f(0, 600));
	ground.setPoint(2, sf::Vector2f(800, 600));
	ground.setPoint(3, sf::Vector2f(800, 475));
	ground.setFillColor(sf::Color(45, 128, 13));
	window->draw(ground);

	//sunce
	sf::CircleShape sunce(100.f);
	sunce.setFillColor(sf::Color(255, 255, 0));
	sunce.setPosition(750, -50);
	window->draw(sunce);

	//animation time management
	sf::Time elapsed = frameClock.restart();
	scale += scaleSpeed * elapsed.asSeconds();
	if (scale >= 2.0f || scale <= 1.0f)
		scaleSpeed = -scaleSpeed;

	//kinda animated zrake sunca
	for (size_t i = 0; i < 7; i++)
	{
		sf::Vector2f size(10.f, (i % 2 == 0) ? 10.f : 7.f);
		sf::RectangleShape zraka(size);

		zraka.setScale(1.f, 30 * scale);
		zraka.setOrigin(zraka.getSize() / 2.0f);
		zraka.setFillColor(sf::Color(255, 255, 0));
		zraka.setPosition(850, 37.5f);
		zraka.setRotation((i + 1) * 15);
		window->draw(zraka);
	}
}