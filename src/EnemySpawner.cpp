#include "EnemySpawner.hpp"
#include "utils.hpp"
#include "Constants.hpp"

EnemySpawner::EnemySpawner(std::vector<Enemy>& enemyVec, sf::Texture& enemyText):
	m_enemyVec(enemyVec),
	m_enemyText(enemyText)
{
	m_spawnClock.restart();
}

void EnemySpawner::updateSpawnCooldown()
{
	if (m_spawnCounter < 10)
		m_spawnCooldown = EnemySpawnCooldownStart;
	else if (m_spawnCounter < 20)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.25f;
	else if (m_spawnCounter < 30)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.5f;
	else if (m_spawnCounter < 50)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.8f;
	else if (m_spawnCounter < 70)
		m_spawnCooldown = EnemySpawnCooldownStart - 0.9f;
	else if (m_spawnCounter < 100)
		m_spawnCooldown = EnemySpawnCooldownStart - 1.1f;

}

void EnemySpawner::update()
{

	if (m_spawnClock.getElapsedTime().asSeconds() < m_spawnCooldown)
		return ;

	
	float enemyX = randomFloat(0, ScreenWidth - EnemyWidth);
	float enemyY = 0 - EnemyHeight;

	m_enemyVec.push_back({enemyX, enemyY, m_enemyText});
	m_spawnCounter++;

	m_spawnClock.restart();

	updateSpawnCooldown();

}
