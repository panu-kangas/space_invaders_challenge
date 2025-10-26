#include "StartState.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "utils.hpp"

StartState::StartState(Game* gamePtr) : 
	IGameState(gamePtr)
{

}


void StartState::update(float dt)
{
	if (m_isReady)
		return ;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) 
	{
        m_isReady = true;
    }
}


void StartState::render(sf::RenderWindow& window)
{
	if (m_isReady)
		return ;

	sf::Font font = m_gamePtr->getMainFont();
	drawHeaderText(font, window, "Space Invaders");
	drawCenteredText(font, window, "Use your spaceship to shoot aliens!");
	drawCenteredText(font, window, "Move using arrow keys, shoot with Space.", 50.f);
	drawLowText(font, window, "Press Enter to start");
}