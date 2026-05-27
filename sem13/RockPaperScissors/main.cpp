#include <iostream>
#include "RPSTournament.h"

int main()
{
	RPSTournament t;

    t.addPlayer(std::make_unique<Rock>());
    t.addPlayer(std::make_unique<Scissors>());
    t.addPlayer(std::make_unique<Paper>());
    t.addPlayer(std::make_unique<Rock>());

    t.simulate();
}

