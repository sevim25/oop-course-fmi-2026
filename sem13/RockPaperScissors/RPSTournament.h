#pragma once
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include <vector>
#include <memory>

class RPSTournament
{
private:
	std::vector<std::unique_ptr<Player>> players;

public:
	void addPlayer(std::unique_ptr<Player> player);
	std::vector<int> calculateScores() const; 
	void printWinner(const std::vector<int>& scores) const;
	void simulate();
};

