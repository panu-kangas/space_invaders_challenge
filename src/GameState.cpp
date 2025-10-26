#include "GameState.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "Enemy.hpp"

GameState::GameState(Game* gamePtr) : 
	IGameState(gamePtr),
	m_player(gamePtr, m_enemies, ScreenWidth / 2, ScreenHeight - 60.f),
	m_scoreHandler(gamePtr),
	m_spawner(m_enemies, gamePtr->getEnemyText())
{
//	initEnemies();
}

/*
void GameState::initEnemies()
{
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 10; ++col) {
			float x = 60 + col * 60;
			float y = 40 + row * 40;
			m_enemies.emplace_back(x, y);
		}
	}
} 
*/

void GameState::removeDestroyedObj()
{
	auto& projVec = m_player.getProjectileVec();

	int i = 0;
	while (i < projVec.size())
	{
		if (projVec[i]->isDestroyed())
		{
			std::swap(projVec[i], projVec.back());
            projVec.pop_back();
            continue;
		}
		i++;
	}

	i = 0;
	while (i < m_enemies.size())
	{
		if (m_enemies[i].isDead())
		{
			m_scoreHandler.addScore(1);
			std::swap(m_enemies[i], m_enemies.back());
            m_enemies.pop_back();
			m_gamePtr->playAlienSound();
            continue;
		}
		i++;
	}
}

/*
void GameState::moveEnemies(float dt)
{
	bool changeDirection = false;
	float offset = 0.0f;
	for (auto& enemy : m_enemies) {
		sf::RectangleShape& enemyShape = enemy.getShape();
		enemyShape.move({m_enemyDir * enemy.getSpeed() * dt, 0});

		sf::Vector2u gameWindowSize = m_gamePtr->getGameWindow().getSize();
		if (enemyShape.getPosition().x <= 0 || enemyShape.getPosition().x + enemyShape.getSize().x >= gameWindowSize.x) {
			float posX = enemyShape.getPosition().x;
			offset = posX < 0.0f ? posX : posX + enemyShape.getSize().x - gameWindowSize.x;
			changeDirection = true;
		}
	}

	if (changeDirection) {
		m_enemyDir *= -1;
		for (auto& enemy : m_enemies) {
			sf::RectangleShape& enemyShape = enemy.getShape();
			enemyShape.move({offset * -1, m_enemyDownOffset});
		}
	}
}
*/

void GameState::update(float dt)
{
	if (m_isReady)
		return ;

	m_spawner.update();
	m_player.update(dt, m_gamePtr->getGameWindow());

	for (auto& enemy : m_enemies)
	{
		if (enemy.update(dt))
			m_isReady = true;
	}

//	moveEnemies(dt);

	removeDestroyedObj();
	m_scoreHandler.update();
}


void GameState::render(sf::RenderWindow& window)
{
	if (m_isReady)
		return ;
	
	for (auto& enemy : m_enemies)
		enemy.draw(window);

	m_player.draw(window);

	m_scoreHandler.draw(window);
}