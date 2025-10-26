#pragma once

#include <SFML/Graphics.hpp>

class Game;
class Enemy;

class Projectile {
public:
    Projectile(Game* gamePtr, std::vector<Enemy>& enemyVec, sf::Vector2f position, float speed = 600.0f);

    void update(float dt);
    void draw(sf::RenderWindow& window);
    bool isOffScreen(const sf::RenderWindow& window) const;
	bool isDestroyed() { return m_isDestroyed; };

private:

	Game* m_gamePtr;
	std::vector<Enemy>& m_enemyVec;

    sf::RectangleShape m_shape;
    float m_speed;
	bool m_isDestroyed = false;
};