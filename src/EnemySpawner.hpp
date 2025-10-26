#pragma once

#include "Enemy.hpp"
#include "Constants.hpp"

class EnemySpawner
{

public:

	EnemySpawner(std::vector<Enemy>& enemyVec);

	void update();

private:

	void spawnNewEnemy();	

	std::vector<Enemy>& m_enemyVec;
	sf::Clock m_spawnClock;
	float m_spawnCooldown = EnemySpawnCooldown;

};