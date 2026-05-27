#include "Scissors.h"


int Scissors::play(const Player& other) const
{
	return other.playWith(*this);
}

int Scissors::playWith(const Rock& rock) const
{
	return -1;
}

int Scissors::playWith(const Paper& paper) const
{
	return 1;
}

int Scissors::playWith(const Scissors& scissors) const
{
	return 0;
}

std::string Scissors::getName() const
{
	return "Scissors";
}
