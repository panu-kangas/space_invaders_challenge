#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "PowerShotBullet.hpp"

Player::Player(Game* gamePtr, std::vector<Enemy>& enemyVec, float x, float y) :
	m_enemyVec(enemyVec)
{
	m_gamePtr = gamePtr;

    m_shape.setSize({50.0f, 20.0f});
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setPosition({x, y});

	m_abilityHandlerPtr = std::make_unique<AbilityHandler>(*this, gamePtr->getMainFont());
}

void Player::shoot()
{
    sf::Vector2f pos = m_shape.getPosition();
    pos.x += m_shape.getSize().x / 2.0f - 2.5f;
    pos.y -= 10.0f;

	m_projectiles.push_back(std::make_unique<Projectile>(m_gamePtr, m_enemyVec, pos));

}

void Player::shootPowerShot()
{
    sf::Vector2f pos = m_shape.getPosition();
    pos.x += m_shape.getSize().x / 2.0f - 2.5f;
    pos.y -= 10.0f;

	m_projectiles.push_back(std::make_unique<PowerShotBullet>(m_gamePtr, m_enemyVec, pos));

}

void Player::update(float dt, sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        m_shape.move({-m_speed * dt, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        m_shape.move({m_speed * dt, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_abilityHandlerPtr->activateAbility(SPEED_BOOST);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_abilityHandlerPtr->activateAbility(POWER_SHOT);
	}

    if (m_shape.getPosition().x < 0)
        m_shape.setPosition({0, m_shape.getPosition().y});
    if (m_shape.getPosition().x + m_shape.getSize().x > ScreenWidth)
        m_shape.setPosition({ScreenWidth - m_shape.getSize().x, m_shape.getPosition().y});

    m_timeSinceLastShot += dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && m_timeSinceLastShot >= m_shootCooldown) {
        shoot();
        m_timeSinceLastShot = 0.0f;
    }

    for (auto& p : m_projectiles)
        p->update(dt);

	m_abilityHandlerPtr->update();

}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
    for (auto& p : m_projectiles)
        p->draw(window);

	m_abilityHandlerPtr->draw(window);
}

