#include "EnemySpawner.hpp"
#include "utils.hpp"
#include "Constants.hpp"

EnemySpawner::EnemySpawner(std::vector<Enemy>& enemyVec):
	m_enemyVec(enemyVec)
{
	m_spawnClock.restart();
}

void EnemySpawner::update()
{

	if (m_spawnClock.getElapsedTime().asSeconds() < m_spawnCooldown)
		return ;

	
	float enemyX = randomFloat(0, ScreenWidth - EnemyWidth);
	float enemyY = 0 - EnemyHeight;

	m_enemyVec.push_back({enemyX, enemyY});

	m_spawnClock.restart();

}
