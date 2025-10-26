#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Game;
class Enemy;

class Projectile {
public:

    Projectile(Game* gamePtr, std::vector<Enemy>& enemyVec, sf::Vector2f position);
	virtual ~Projectile() = default;

    virtual void update(float dt);
    void draw(sf::RenderWindow& window);
    bool isOffScreen(const sf::RenderWindow& window) const;
	bool isDestroyed() { return m_isDestroyed; };

protected:

	Game* m_gamePtr;
	std::vector<Enemy>& m_enemyVec;

    sf::RectangleShape m_shape;
    float m_speed = ProjectileSpeed;
	bool m_isDestroyed = false;
};