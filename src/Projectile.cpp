#include "Projectile.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "utils.hpp"

Projectile::Projectile(Game* gamePtr, std::vector<Enemy>& enemyVec, sf::Vector2f position, float speed) : 
	m_speed(speed),
	m_enemyVec(enemyVec)
{
    m_shape.setSize({5.0f, 15.0f});
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(position);

	m_gamePtr = gamePtr;
}

void Projectile::update(float dt)
{
	if (m_isDestroyed)
		return ;

    m_shape.move({0.0f, -m_speed * dt});

	for (auto& enemy : m_enemyVec)
	{
		if (checkRectCollision(m_shape, enemy.getShape()))
		{
			enemy.setDead();
			m_isDestroyed = true;
			break ;
		}
	}

	if (isOffScreen(m_gamePtr->getGameWindow()))
	{
		m_isDestroyed = true;
	}

}

void Projectile::draw(sf::RenderWindow& window)
{
	if (m_isDestroyed)
		return ;

    window.draw(m_shape);
}

bool Projectile::isOffScreen(const sf::RenderWindow& window) const
{
    return m_shape.getPosition().y + m_shape.getSize().y < 0;
} 
