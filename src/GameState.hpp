#pragma once

#include "IGameState.hpp"
#include "Constants.hpp"
#include "Player.hpp"
#include "ScoreHandler.hpp"

class Enemy;
class Game;

class GameState : public IGameState
{

public:

	GameState()  = delete;
	GameState(Game* gamePtr);

	void update(float dt) override;
    void render(sf::RenderWindow& window) override;

	std::vector<Enemy>& getEnemyVec() { return m_enemies; };
	int getScore() override { return m_scoreHandler.getScore(); };


private:

	void initEnemies();
	void moveEnemies(float dt);
	void removeDestroyedObj();

	std::vector<Enemy> m_enemies;
	Player m_player;
	ScoreHandler m_scoreHandler;

	float m_enemyDir = EnemyStartDirection;
	float m_enemyDownOffset = EnemyDownMoveOffset;

};