#pragma once
#include <string>

class Rock;
class Paper;
class Scissors;

class Player
{
public:
	virtual int play(const Player& other) const = 0;

	virtual int playWith(const Rock& rock) const = 0;
	virtual int playWith(const Paper& paper) const = 0;
	virtual int playWith(const Scissors& scissors) const = 0;

	virtual std::string getName() const = 0;

	virtual ~Player() = default;
};

