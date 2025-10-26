#include "Enemy.hpp"

Enemy::Enemy(float x, float y)
{
	m_shape.setSize(sf::Vector2f(40.0f, 20.0f));
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setPosition({x, y});
}

bool Enemy::update(float dt) 
{
	if (m_isDead)
		return false;
	
	sf::Vector2f direction {0, m_speed};
	m_shape.move(direction * dt);

	if (m_shape.getPosition().y >= EnemyWinY)
		return true;

	return false;
}

void Enemy::draw(sf::RenderWindow& window) 
{
	if (m_isDead)
		return ;

	window.draw(m_shape);
}