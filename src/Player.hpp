#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"

class Game;

class Player {
public:
    Player(Game* gamePtr, float x, float y);

    void update(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape() { return m_shape; };
	std::vector<Projectile>& getProjectileVec() { return m_projectiles; };

private:

	Game* m_gamePtr;

    sf::RectangleShape m_shape;
    float m_speed = 300.0f;

    std::vector<Projectile> m_projectiles;
    float m_shootCooldown = 0.3f;
    float m_timeSinceLastShot = 0.0f;

    void shoot();
};
