#include "encoding.h"

Encoding::Encoding() {}
Encoding::Encoding(char _ch, int _code): ch(_ch), code(_code) {}

char Encoding::getChar() const
{
    return ch;
}

int Encoding::getCode() const
{
    return code;
}
