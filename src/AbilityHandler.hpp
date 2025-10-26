#pragma once

#include <SFML/Graphics.hpp>
#include "SpeedAbility.hpp"
#include "PowerShotAbility.hpp"

class Player;

enum eAbilities
{
	SPEED_BOOST,
	POWER_SHOT
};

class AbilityHandler
{

public:

	AbilityHandler() = delete;
	AbilityHandler(Player& player, sf::Font& font);

	void activateAbility(eAbilities abilityType);
	void update();
	void draw(sf::RenderWindow& window);
	sf::Color getTextColor(AbilityBase* ability);


private:

	SpeedAbility m_speedAbility;
	PowerShotAbility m_powerShotAbility;

	sf::Font& m_font;
	sf::RectangleShape m_box;

	sf::Text m_speedText;
	sf::Text m_speedCtrlText;

	sf::Text m_powerShotText;
	sf::Text m_powerShotCtrlText;


};