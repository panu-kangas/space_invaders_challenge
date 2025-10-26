#include "PowerShotBullet.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "utils.hpp"


PowerShotBullet::PowerShotBullet(Game* gamePtr, std::vector<Enemy>& enemyVec, sf::Vector2f position) : Projectile(gamePtr, enemyVec, position)
{
	m_shape.setSize({30.0f, 40.0f});
    m_shape.setFillColor(sf::Color::Yellow);
}

void PowerShotBullet::update(float dt)
{
	if (m_isDestroyed)
		return ;

    m_shape.move({0.0f, -m_speed * dt});

	for (auto& enemy : m_enemyVec)
	{
		if (checkRectCollision(m_shape, enemy.getShape()))
		{
			enemy.setDead();
			break ;
		}
	}

	if (isOffScreen(m_gamePtr->getGameWindow()))
	{
		m_isDestroyed = true;
	}
}