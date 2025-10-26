#pragma once

#include "Enemy.hpp"
#include "Constants.hpp"

class EnemySpawner
{

public:

	EnemySpawner(std::vector<Enemy>& enemyVec, sf::Texture& enemyText);

	void update();

private:

	void updateSpawnCooldown();

	std::vector<Enemy>& m_enemyVec;
	sf::Clock m_spawnClock;
	sf::Texture& m_enemyText;
	float m_spawnCooldown = EnemySpawnCooldownStart;
	int m_spawnCounter = 0;

};