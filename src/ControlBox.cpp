#include "ControlBox.hpp"
#include "Game.hpp"

ControlBox::ControlBox(Game* gamePtr) : 
	m_font(gamePtr->getMainFont()),
	m_headerText(m_font, "Controls")
{
	m_box.setSize({100.f, 200.f});
	sf::Vector2f boxSize = m_box.getSize();
	m_box.setPosition({ScreenWidth - boxSize.x, ScreenHeight - boxSize.y});
	m_box.setOutlineThickness(2.f);
	m_box.setOutlineColor(sf::Color::White);
	m_box.setFillColor(sf::Color(128, 128, 128, 170));

	sf::Vector2f boxPos = m_box.getPosition();
	float headerPosX = boxPos.x + boxSize.x / 2 - m_headerText.getLocalBounds().size.x / 2;
	float headerPosY = boxPos.y + 20.f;
	m_headerText.setPosition({boxPos.x + boxSize.x / 2, headerPosY});
}


void ControlBox::draw(sf::RenderWindow& window)
{
	window.draw(m_box);
	window.draw(m_headerText);
}
