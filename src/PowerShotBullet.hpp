#pragma once

#include "Projectile.hpp"

class PowerShotBullet : public Projectile
{

public:

	PowerShotBullet() = delete;
	PowerShotBullet(Game* gamePtr, std::vector<Enemy>& enemyVec, sf::Vector2f position);

	void update(float dt) override;


private:



};