#include "Paper.h"

int Paper::play(const Player& other) const
{
	return other.playWith(*this);
}

int Paper::playWith(const Rock& rock) const
{
	return 1;
}

int Paper::playWith(const Paper& paper) const
{
	return 0;
}

int Paper::playWith(const Scissors& scissors) const
{
	return -1;
}

std::string Paper::getName() const
{
	return "Paper";
}
