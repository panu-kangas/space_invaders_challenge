#include "SpeedAbility.hpp"
#include "Constants.hpp"
#include "Player.hpp"

#include <iostream>

SpeedAbility::SpeedAbility(Player& player) : AbilityBase(player)
{
	m_cooldown = SpeedAbilityCooldown;
	m_effectTime = SpeedAbilityEffectTime;
	m_cooldownClock.restart();
}

void SpeedAbility::activate()
{
	if (m_isActive || m_cooldownClock.getElapsedTime().asSeconds() < SpeedAbilityCooldown)
		return ;

	m_player.addSpeed(SpeedAbilityEffect);
	m_effectTimeClock.restart();
	m_isActive = true;
	m_cooldownBar.setSize({0, m_cooldownBar.getSize().y});
}


void SpeedAbility::update()
{
	updateCooldownBar();

	if (!m_isActive)
		return ;

	if (m_effectTimeClock.getElapsedTime().asSeconds() > SpeedAbilityEffectTime)
	{
		m_player.resetSpeed();
		m_cooldownClock.restart();
		m_isActive = false;
	}
}
