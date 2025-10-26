#include "AbilityHandler.hpp"
#include "Player.hpp"
#include "Constants.hpp"

AbilityHandler::AbilityHandler(Player& player, sf::Font& font) : 
	m_speedAbility(player),
	m_powerShotAbility(player),
	m_font(font),
	m_speedText(m_font, "Speed boost"),
	m_speedCtrlText(m_font, "Press A"),
	m_powerShotText(m_font, "Power Shot"),
	m_powerShotCtrlText(m_font, "Press S")
{
	// Set BG
	m_box.setSize({330.f, 100.f});
	float boxSizeX = m_box.getSize().x;
	m_box.setPosition({ScreenWidth - boxSizeX, 0});
	m_box.setOutlineThickness(2.f);
	m_box.setOutlineColor(sf::Color::White);
	m_box.setFillColor(sf::Color(128, 128, 128, 170));

	// Set Speed Boost texts
	m_speedText.setFillColor(getTextColor(&m_speedAbility));
	m_speedText.setCharacterSize(25.f);
	float padding = 20.f;
	float speedTextX = m_box.getPosition().x + padding;
	m_speedText.setPosition({speedTextX, padding});

	// Set cooldown shape pos
	float cooldownBarX = m_speedText.getPosition().x;
	float cooldownBarY = m_speedText.getPosition().y + m_speedText.getLocalBounds().size.y + 20.f;
	sf::RectangleShape& rect = m_speedAbility.getCooldownBarShape();
	rect.setPosition({cooldownBarX, cooldownBarY});

	m_speedCtrlText.setCharacterSize(20.f);
	float ctrlX = speedTextX + m_speedText.getLocalBounds().size.x / 2 - m_speedCtrlText.getLocalBounds().size.x / 2;
	float ctrlY = cooldownBarY + 15.f;
	m_speedCtrlText.setPosition({ctrlX, ctrlY});


	// Set Power Shot texts
	m_powerShotText.setFillColor(getTextColor(&m_powerShotAbility));
	m_powerShotText.setCharacterSize(25.f);
	float powerShotX = speedTextX + m_speedText.getLocalBounds().size.x + padding;
	m_powerShotText.setPosition({powerShotX, padding});

	// Set cooldown shape pos
	cooldownBarX = m_powerShotText.getPosition().x;
	cooldownBarY = m_powerShotText.getPosition().y + m_powerShotText.getLocalBounds().size.y + 20.f;
	sf::RectangleShape& rect2 = m_powerShotAbility.getCooldownBarShape();
	rect2.setPosition({cooldownBarX, cooldownBarY});

	m_powerShotCtrlText.setCharacterSize(20.f);
	ctrlX = powerShotX + m_powerShotText.getLocalBounds().size.x / 2 - m_powerShotCtrlText.getLocalBounds().size.x / 2;
	ctrlY = cooldownBarY + 15.f;
	m_powerShotCtrlText.setPosition({ctrlX, ctrlY});

}

void AbilityHandler::activateAbility(eAbilities abilityType)
{
	switch (abilityType)
	{
		case SPEED_BOOST:
		{
			m_speedAbility.activate();
			break ;
		}

		case POWER_SHOT:
		{
			m_powerShotAbility.activate();
			break ;
		}

		default:
		{
			break ;
		}
	}
}

void AbilityHandler::update()
{
	m_speedAbility.update();
	m_powerShotAbility.update();
}

sf::Color AbilityHandler::getTextColor(AbilityBase* ability)
{
	
	if (ability->isActive())
		return sf::Color::Yellow;
	else if (ability->isReadyForUse())
		return sf::Color::Green;
	else
		return sf::Color::Red;

}


void AbilityHandler::draw(sf::RenderWindow& window)
{
	m_speedText.setFillColor(getTextColor(&m_speedAbility));
	m_powerShotText.setFillColor(getTextColor(&m_powerShotAbility));

	window.draw(m_box);
	window.draw(m_speedText);
	window.draw(m_speedAbility.getCooldownBarShape());
	window.draw(m_speedCtrlText);
	window.draw(m_powerShotText);
	window.draw(m_powerShotAbility.getCooldownBarShape());
	window.draw(m_powerShotCtrlText);

}
