#include "EnemySpawner.hpp"
#include "utils.hpp"
#include "Constants.hpp"

EnemySpawner::EnemySpawner(std::vector<Enemy>& enemyVec):
	m_enemyVec(enemyVec)
{
	m_spawnClock.restart();
}

void EnemySpawner::updateSpawnCooldown()
{
	if (m_spawnCounter < 10)
		m_spawnCooldown = EnemySpawnCooldownStart;
	else if (m_spawnCounter < 20)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.3f;
	else if (m_spawnCounter < 40)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.5f;
	else if (m_spawnCounter < 60)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.8f;
	else if (m_spawnCounter < 100)
		m_spawnCooldown = EnemySpawnCooldownStart - 1.0f;

}

void EnemySpawner::update()
{

	if (m_spawnClock.getElapsedTime().asSeconds() < m_spawnCooldown)
		return ;

	
	float enemyX = randomFloat(0, ScreenWidth - EnemyWidth);
	float enemyY = 0 - EnemyHeight;

	m_enemyVec.push_back({enemyX, enemyY});
	m_spawnCounter++;

	m_spawnClock.restart();

	updateSpawnCooldown();

}
