#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Player.hpp"
#include "Enemy.hpp"
#include "ScoreHandler.hpp"
#include "IGameState.hpp"

enum eGameState
{
	START,
	GAME,
	END
};

class Game {

public:

    Game();

    void run();
    void processEvents();
    void update();
    void render();

	sf::Font& getMainFont() { return m_mainFont; };
	sf::RenderWindow& getGameWindow() { return m_window; };

private:

    sf::RenderWindow m_window;
    sf::Clock clock;
	sf::Font m_mainFont;

    std::unique_ptr<IGameState> m_curStatePtr;
	eGameState m_state{START};
	
};