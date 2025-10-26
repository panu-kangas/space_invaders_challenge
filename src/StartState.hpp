#pragma once

#include "IGameState.hpp"

class Game;

class StartState : public IGameState
{

public:

	StartState()  = delete;
	StartState(Game* gamePtr);

	void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:

};