#pragma once

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Enemy.hpp"

class Game {

public:

    Game();

    void initEnemies();
    void run();
    void processEvents();
    void update();
    void render();

private:

    sf::RenderWindow window;
    Player player;
    std::vector<Enemy> enemies;
    float enemyDirection = 1.0f;
    float enemyMoveDown = 20.0f;
    float enemySpeed = 50.0f;
    sf::Clock clock;
};