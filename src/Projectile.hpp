#pragma once

#include <SFML/Graphics.hpp>

class Projectile {
public:
    Projectile(sf::Vector2f position, float speed = 600.0f);

    void update(float dt);
    void draw(sf::RenderWindow& window);
    bool isOffScreen(const sf::RenderWindow& window) const;

private:
    sf::RectangleShape shape;
    float speed;
};