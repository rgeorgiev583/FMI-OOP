#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    char name[50];
    bool has_lost;

public:
    Player(const char* = "");

    const char* getName() const;
    bool hasLost() const;

    void lose();
};

#endif // PLAYER_H_INCLUDED
