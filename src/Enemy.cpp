#include "Enemy.hpp"

Enemy::Enemy(float x, float y)
{
	shape.setSize(sf::Vector2f(40.0f, 20.0f));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition({x, y});
}

void Enemy::update(float dt) 
{
	if (m_isDead)
		return ;
	
	sf::Vector2f direction {m_speed, 0};
	shape.move(direction * dt);
}


void Enemy::draw(sf::RenderWindow& window) 
{
	if (m_isDead)
		return ;

	window.draw(shape);
}