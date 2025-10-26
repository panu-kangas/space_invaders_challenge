#pragma once

#include <SFML/Graphics.hpp>

class Player;

class AbilityBase
{
public:

	AbilityBase() = delete;
	AbilityBase(Player& player);
	virtual ~AbilityBase() = default;

	virtual void activate() = 0;
	virtual void update() = 0;

	bool isActive() { return m_isActive; };
	bool isReadyForUse() { return m_cooldownClock.getElapsedTime().asSeconds() > m_cooldown; };
	void updateCooldownBar();
	sf::RectangleShape& getCooldownBarShape() { return m_cooldownBar; };

protected:

	Player& m_player;

	bool m_isActive = false;
//	float m_effect = 0.f;
	float m_effectTime = 0.f;
	float m_cooldown  = 0.f;
	sf::Clock m_cooldownClock;
	sf::Clock m_effectTimeClock;

	sf::RectangleShape m_cooldownBar;

};