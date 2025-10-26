#include "AbilityBase.hpp"
#include "Constants.hpp"

AbilityBase::AbilityBase(Player& player) : m_player(player)
{
	m_cooldownBar.setSize({CooldownBarLength, 12.f});
	m_cooldownBar.setFillColor(sf::Color::Blue);
}


void AbilityBase::updateCooldownBar()
{
	if (isReadyForUse())
	{
		if (m_cooldownBar.getFillColor() != sf::Color::Green)
			m_cooldownBar.setFillColor(sf::Color::Green);
		return ;
	}

	if (m_cooldownBar.getFillColor() != sf::Color::Blue)
			m_cooldownBar.setFillColor(sf::Color::Blue);


	float barLength = CooldownBarLength * (m_cooldownClock.getElapsedTime().asSeconds() / m_cooldown);
	
	m_cooldownBar.setSize({barLength, m_cooldownBar.getSize().y});

}
