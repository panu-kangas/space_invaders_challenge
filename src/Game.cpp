#include "Game.hpp"
#include "Constants.hpp"

Game::Game() :
	window(sf::VideoMode({ScreenWidth, ScreenHeight}), "Space Invaders - Base Game Jam"),
	player(375.0f, 550.0f) 
{

	initEnemies();
}

void Game::run()
{
	while (window.isOpen()) {
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
			enemies.emplace_back(x, y);
		}
	}
}

void Game::processEvents()
{
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update()
{
	float dt = clock.restart().asSeconds();
	player.update(dt, window);

	// Move enemies
	bool changeDirection = false;
	float offset = 0.0f;
	for (auto& enemy : enemies) {
		sf::RectangleShape& enemyShape = enemy.getShape();
		enemyShape.move({enemyDirection * enemySpeed * dt, 0});
		if (enemyShape.getPosition().x <= 0 || enemyShape.getPosition().x + enemyShape.getSize().x >= window.getSize().x) {
			float posX = enemyShape.getPosition().x;
			offset = posX < 0.0f ? posX : posX + enemyShape.getSize().x - window.getSize().x;
			changeDirection = true;
		}
	}

	if (changeDirection) {
		enemyDirection *= -1;
		for (auto& enemy : enemies) {
			sf::RectangleShape& enemyShape = enemy.getShape();
			enemyShape.move({offset * -1, enemyMoveDown});
		}
	}
}

void Game::render()
{
	window.clear(sf::Color::Black);
	player.draw(window);

	for (auto& enemy : enemies)
		enemy.draw(window);
	window.display();
}