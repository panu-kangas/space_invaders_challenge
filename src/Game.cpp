#include "Game.hpp"
#include "Constants.hpp"
#include "Projectile.hpp"

#include <iostream>

Game::Game() :
	m_window(sf::VideoMode({ScreenWidth, ScreenHeight}), "Space Invaders - Base Game Jam"),
	player(this, ScreenWidth / 2, ScreenHeight - 30.f),
	m_scoreHandler(this)
{

	initEnemies();

	if (!m_mainFont.openFromFile("assets/mainFont.ttf"))
	{
		std::cout << "Font download failed!\nExiting program...\n";
		exit(1);
	}
}

void Game::run()
{
	while (m_window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::initEnemies()
{
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 10; ++col) {
			float x = 60 + col * 60;
			float y = 40 + row * 40;
			m_enemies.emplace_back(x, y);
		}
	}
}

void Game::processEvents()
{
    while (auto event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            m_window.close();
    }
}

void Game::update()
{
	float dt = clock.restart().asSeconds();

	player.update(dt, m_window);
	moveEnemies(dt);

	removeDestroyedObj();

}

void Game::removeDestroyedObj()
{
	auto& projVec = player.getProjectileVec();

	int i = 0;
	while (i < projVec.size())
	{
		if (projVec[i].isDestroyed())
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
			std::swap(m_enemies[i], m_enemies.back());
            m_enemies.pop_back();
            continue;
		}
		i++;
	}
}


void Game::moveEnemies(float dt)
{
	bool changeDirection = false;
	float offset = 0.0f;
	for (auto& enemy : m_enemies) {
		sf::RectangleShape& enemyShape = enemy.getShape();
		enemyShape.move({enemyDirection * enemySpeed * dt, 0});
		if (enemyShape.getPosition().x <= 0 || enemyShape.getPosition().x + enemyShape.getSize().x >= m_window.getSize().x) {
			float posX = enemyShape.getPosition().x;
			offset = posX < 0.0f ? posX : posX + enemyShape.getSize().x - m_window.getSize().x;
			changeDirection = true;
		}
	}

	if (changeDirection) {
		enemyDirection *= -1;
		for (auto& enemy : m_enemies) {
			sf::RectangleShape& enemyShape = enemy.getShape();
			enemyShape.move({offset * -1, enemyMoveDown});
		}
	}
}


void Game::render()
{
	m_window.clear(sf::Color::Black);
	player.draw(m_window);

	for (auto& enemy : m_enemies)
		enemy.draw(m_window);

	
	m_scoreHandler.draw(m_window);

	m_window.display();
}