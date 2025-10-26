#pragma once

#include <SFML/Graphics.hpp>

class Enemy {

public:

	Enemy(float x, float y);

	void update(float dt);
	void draw(sf::RenderWindow& window);

	sf::RectangleShape& getShape() { return shape; };
	bool isDead() { return m_isDead; };
	void setDead() { m_isDead = true; };

private:

	sf::RectangleShape shape;
	float speed = 50.0f;
	bool m_isDead = false;

};