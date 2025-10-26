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
	drawCenteredText(font, window, "Use your spaceship to shoot aliens!", -20.f);
	drawCenteredText(font, window, "Move using arrow keys, shoot with D.", 50.f, true);
	drawCenteredText(font, window, "Use power-ups to your advantage:", 100.f, true);
	drawCenteredText(font, window, "Press S for Speed Boost that makes you faster", 150.f, true);
	drawCenteredText(font, window, "Press A for Power Shot pierces through enemies.", 200.f, true);
	drawCenteredText(font, window, "If enemies reach the bottom, you lose.", 250.f, true);
	drawLowText(font, window, "Press Enter to start");
}
