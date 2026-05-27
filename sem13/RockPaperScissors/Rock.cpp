#include "Rock.h"

int Rock::play(const Player& other) const
{
	return other.playWith(*this);
}

int Rock::playWith(const Rock& rock) const
{
	return 0;
}

int Rock::playWith(const Paper& paper) const
{
	return 1;
}

int Rock::playWith(const Scissors& scissors) const
{
	return -1;
}

std::string Rock::getName() const
{
	return "Rock";
}
