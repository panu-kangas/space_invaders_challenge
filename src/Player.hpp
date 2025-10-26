#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"

class Game;
class Enemy;

class Player {
public:
    Player(Game* gamePtr, std::vector<Enemy>& enemyVec, float x, float y);

    void update(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape() { return m_shape; };
	std::vector<std::unique_ptr<Projectile>>& getProjectileVec() { return m_projectiles; };

private:

	Game* m_gamePtr;
	std::vector<Enemy>& m_enemyVec;

    sf::RectangleShape m_shape;
    float m_speed = 300.0f;

    std::vector<std::unique_ptr<Projectile>> m_projectiles;
    float m_shootCooldown = 0.3f;
    float m_timeSinceLastShot = 0.0f;

    void shoot();
};
