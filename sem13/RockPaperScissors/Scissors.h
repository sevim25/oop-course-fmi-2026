#pragma once
#include "Player.h"


class Scissors : public Player
{
	int play(const Player& other) const override;

	int playWith(const Rock& rock) const override;
	int playWith(const Paper& paper) const override;
	int playWith(const Scissors& scissors) const override;

	std::string getName() const override;
};

