#include <iostream>
#include "game.h"
using namespace std;

int main()
{
	Game game(2);
	game.addPlayer("Ivan");
	game.addPlayer("Pesho");
	game.addPlayer("Sasho");
	game.addPlayer("Kosio");

	while (!game.hasFinished())
        game.play();

    cout << game;

	return 0;
}
