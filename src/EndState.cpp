#include "EndState.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "utils.hpp"

EndState::EndState(Game* gamePtr, int score) : 
	IGameState(gamePtr)
{
	m_scoreStr = std::to_string(score);
}


void EndState::update(float dt)
{
	if (m_isReady)
		return ;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) 
	{
        m_isReady = true;
    }
}


void EndState::render(sf::RenderWindow& window)
{
	if (m_isReady)
		return ;
	
	sf::Font font = m_gamePtr->getMainFont();
	
	drawHeaderText(font, window, "Game Over");
	drawCenteredText(font, window, "Your Score is:");

	sf::Text scoreText(font, m_scoreStr);

	scoreText.setFillColor(sf::Color::White);
	scoreText.setCharacterSize(RegularTextSize);

	float scoreTextX = ScreenWidth / 2 - scoreText.getLocalBounds().size.x / 2;
	float scoreTextY = ScreenHeight / 2 - scoreText.getLocalBounds().size.y / 2 + 50.f;
	scoreText.setPosition({scoreTextX, scoreTextY});

	window.draw(scoreText);
}