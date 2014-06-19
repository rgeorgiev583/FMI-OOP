#include "player.h"
#include <cstring>

Player::Player(const char* _name = "")
{
    strcpy(name, strlen(_name) < 50 ? _name : "(Name too long to be displayed)");
}

const char* Player::getName() const
{
    return name;
}

bool Player::hasLost() const
{
    return has_lost;
}

void Player::lose()
{
    has_lost = true;
}
