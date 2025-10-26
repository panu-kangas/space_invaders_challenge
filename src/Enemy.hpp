#pragma once

#include <SFML/Graphics.hpp>

class Enemy {

public:

	Enemy(float x, float y);

	void update(float dt);
	void draw(sf::RenderWindow& window);

	sf::RectangleShape& getShape() { return shape; };

private:

	sf::RectangleShape shape;
	float speed = 50.0f;

};