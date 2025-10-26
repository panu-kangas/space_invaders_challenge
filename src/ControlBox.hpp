#pragma once

#include <SFML/Graphics.hpp>

class Game;

class ControlBox
{

public:

	ControlBox() = delete;
	ControlBox(Game* gamePtr);

	void draw(sf::RenderWindow& window);

private:

	sf::Font m_font;
	sf::RectangleShape m_box;
	sf::Text m_headerText;

};