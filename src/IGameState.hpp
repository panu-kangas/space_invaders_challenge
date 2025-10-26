#pragma once

#include <SFML/Graphics.hpp>

class Game;

class IGameState 
{

public:

	IGameState() = delete;
	IGameState(Game* gamePtr) { m_gamePtr = gamePtr; };
    virtual ~IGameState() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
	virtual int getScore() { return 0; };

	bool isReady() { return m_isReady; };

protected:

	Game* m_gamePtr;
	bool m_isReady{false};
};