#include "Enemy.hpp"

Enemy::Enemy(float x, float y)
{
	shape.setSize(sf::Vector2f(40.0f, 20.0f));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition({x, y});
}

void Enemy::update(float dt) 
{
	sf::Vector2f direction {speed, 0};
	shape.move(direction * dt);
}


void Enemy::draw(sf::RenderWindow& window) 
{
	window.draw(shape);
}