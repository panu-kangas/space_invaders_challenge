#include "PowerShotAbility.hpp"
#include "Constants.hpp"
#include "Projectile.hpp"
#include "Player.hpp"

#include <iostream>

PowerShotAbility::PowerShotAbility(Player& player) : 
	AbilityBase(player)
{
	m_cooldown = PowerShotAbilityCooldown;
	m_effectTime = PowerShotAbilityEffectTime;
	m_cooldownClock.restart();
}

void PowerShotAbility::activate()
{
	if (m_isActive || m_cooldownClock.getElapsedTime().asSeconds() < PowerShotAbilityCooldown)
		return ;

	m_player.shootPowerShot();
	m_effectTimeClock.restart();
	m_isActive = true;
	m_cooldownBar.setSize({0, m_cooldownBar.getSize().y});
}


void PowerShotAbility::update()
{
	updateCooldownBar();

	if (!m_isActive)
		return ;

	if (m_effectTimeClock.getElapsedTime().asSeconds() > PowerShotAbilityEffectTime)
	{
		m_cooldownClock.restart();
		m_isActive = false;
	}
}