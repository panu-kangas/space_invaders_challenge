#include "Projectile.hpp"

Projectile::Projectile(sf::Vector2f position, float speed)
    : speed(speed)
{
    shape.setSize({5.0f, 15.0f});
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

void Projectile::update(float dt)
{
    shape.move({0.0f, -speed * dt});
}

void Projectile::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

bool Projectile::isOffScreen(const sf::RenderWindow& window) const
{
    return shape.getPosition().y + shape.getSize().y < 0;
} 
