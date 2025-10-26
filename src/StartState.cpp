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

	drawHeaderText(m_gamePtr->getMainFont(), window, "Space Invaders");
}