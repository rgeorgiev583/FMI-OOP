#pragma once

class Encoding
{
    char ch;
    int code;

public:
    Encoding();
    Encoding(char, int);
    char getChar() const;
    int getCode() const;
};
