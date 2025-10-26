#pragma once

#include "IGameState.hpp"

class Game;

class EndState : public IGameState
{

public:

	EndState()  = delete;
	EndState(Game* gamePtr, int score);

	void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:

	std::string m_scoreStr;
};