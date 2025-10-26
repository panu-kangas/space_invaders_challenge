#pragma once

#include "AbilityBase.hpp"

class SpeedAbility : public AbilityBase
{

public:

	SpeedAbility() = delete;
	SpeedAbility(Player& player);

	void activate() override;
	void update() override;

private:



};