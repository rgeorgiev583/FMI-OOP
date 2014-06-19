#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include "player.h"

class Game
{
    Player players[20];
    size_t playerCount, maxTurns, currentPlayer, numberOfTurns, numberOfLosers;

public:
    Game(size_t);

    bool hasFinished() const;

    void addPlayer(const char*);
    void play(std::ostream& = std::cout);

    friend std::ostream& operator<<(std::ostream&, const Game&);
};

#endif // GAME_H_INCLUDED
