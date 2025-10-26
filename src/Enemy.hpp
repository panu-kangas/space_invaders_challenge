#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Enemy {

public:

	Enemy(float x, float y);

	bool update(float dt);
	void draw(sf::RenderWindow& window);

	sf::RectangleShape& getShape() { return m_shape; };
	float getSpeed() { return m_speed; };
	bool isDead() { return m_isDead; };
	void setDead() { m_isDead = true; };

private:

	sf::RectangleShape m_shape;
	float m_speed = EnemySpeed;
	bool m_isDead = false;

};