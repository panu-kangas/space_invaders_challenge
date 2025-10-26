#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"

class Player {
public:
    Player(float x, float y);

    void update(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape() { return shape; };

private:
    sf::RectangleShape shape;
    float speed = 300.0f;

    std::vector<Projectile> projectiles;
    float shootCooldown = 0.3f;
    float timeSinceLastShot = 0.0f;

    void shoot();
};
