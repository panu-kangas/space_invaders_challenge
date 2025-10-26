#pragma once

#include "AbilityBase.hpp"

class Projectile;

class PowerShotAbility : public AbilityBase
{

public:

	PowerShotAbility() = delete;
	PowerShotAbility(Player& player);

	void activate() override;
	void update() override;

	void setHasShot(bool value) { m_hasShot = value; };
	bool getHasShot() { return m_hasShot; };

private:

	bool m_hasShot = false;

};