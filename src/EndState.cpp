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
	drawCenteredText(font, window, m_scoreStr, 50.f);

}