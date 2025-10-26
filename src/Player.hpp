#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Projectile.hpp"
#include "Constants.hpp"
#include "AbilityHandler.hpp" 

class Game;
class Enemy;

class Player {
public:
    Player(Game* gamePtr, std::vector<Enemy>& enemyVec, float x, float y);

    void update(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

	void addSpeed(float speedAddition) { m_speed += speedAddition; };
	void resetSpeed() { m_speed = PlayerInitSpeed; };
	void shootPowerShot();
    sf::RectangleShape& getShape() { return m_shape; };
	std::vector<std::unique_ptr<Projectile>>& getProjectileVec() { return m_projectiles; };

private:

    void shoot();

	Game* m_gamePtr;

	std::vector<Enemy>& m_enemyVec;
    std::vector<std::unique_ptr<Projectile>> m_projectiles;
	std::unique_ptr<AbilityHandler> m_abilityHandlerPtr;

    sf::RectangleShape m_shape;

    float m_speed = PlayerInitSpeed;
    float m_shootCooldown = 0.4f;
    float m_timeSinceLastShot = 0.0f;

};
