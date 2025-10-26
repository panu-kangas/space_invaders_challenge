#pragma once

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Enemy.hpp"
#include "ScoreHandler.hpp"

class Game {

public:

    Game();

    void initEnemies();
	void moveEnemies(float dt);
	void removeDestroyedObj();
    void run();
    void processEvents();
    void update();
    void render();


	sf::Font& getMainFont() { return m_mainFont; };
	std::vector<Enemy>& getEnemyVec() { return m_enemies; };
	sf::RenderWindow& getGameWindow() { return m_window; };


private:

    sf::RenderWindow m_window;
    Player player;
    std::vector<Enemy> m_enemies;
    float enemyDirection = 1.0f;
    float enemyMoveDown = 20.0f;
    float enemySpeed = 50.0f;
    sf::Clock clock;

	sf::Font m_mainFont;

	ScoreHandler m_scoreHandler;
};