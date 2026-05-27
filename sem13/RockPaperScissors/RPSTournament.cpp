#include "RPSTournament.h"
#include <iostream>

void RPSTournament::addPlayer(std::unique_ptr<Player> player)
{
	players.push_back(std::move(player));
}

std::vector<int> RPSTournament::calculateScores() const
{
    int n = players.size();
    std::vector<int> scores(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int res = players[i]->play(*players[j]);
            scores[i] += res;
            scores[j] -= res;
        }
    }
    return scores;
}

void RPSTournament::printWinner(const std::vector<int>& scores) const
{
    if (scores.empty()) return;

    int winner = 0;
    for (size_t i = 1; i < scores.size(); ++i) {
        if (scores[i] > scores[winner]) {
            winner = i;
        }
    }
    std::cout << "The winner is: " << players[winner]->getName();
}

void RPSTournament::simulate()
{
    std::vector<int> finalScores = calculateScores();
    printWinner(finalScores);
}
