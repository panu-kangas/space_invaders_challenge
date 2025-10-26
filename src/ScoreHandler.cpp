#include "ScoreHandler.hpp"
#include "Game.hpp"


ScoreHandler::ScoreHandler(Game* gamePtr) : 
	m_scoreText(gamePtr->getMainFont(), std::to_string(m_score)),
	m_infoText(gamePtr->getMainFont(), "Your score is:")
{
	m_gamePtr = gamePtr;

	m_box.setPosition({0, 0});
	m_box.setSize({200.f, 100.f});
	m_box.setOutlineThickness(2.f);
	m_box.setOutlineColor(sf::Color::White);
	m_box.setFillColor(sf::Color(128, 128, 128, 170));

	float padding = 10.f;

	m_infoText.setCharacterSize(30.f);
	m_infoText.setFillColor(sf::Color::White);
	m_infoText.setPosition({m_box.getPosition().x + padding, m_box.getPosition().y + padding});

	m_scoreText.setCharacterSize(30.f);
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setPosition({m_infoText.getPosition().x, m_infoText.getPosition().y + 35.f});


}

void ScoreHandler::addScore(int addition)
{
	m_score += addition;
}


void ScoreHandler::reset()
{
	m_score = 0;
}


void ScoreHandler::update()
{
	m_scoreText.setString(std::to_string(m_score));
}


void ScoreHandler::draw(sf::RenderWindow& window)
{
	window.draw(m_box);
	window.draw(m_infoText);
	window.draw(m_scoreText);
}
