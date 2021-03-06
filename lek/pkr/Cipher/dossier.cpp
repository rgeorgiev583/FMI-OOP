#include <iostream>
#include "dossier.h"

void Dossier::copy(const Dossier& other)
{
    text = new int[other.textlength];

    for (size_t i = 0; i < other.textlength; i++)
        text[i] = other.text[i];

    cipher = new Encoding[other.cipherlength];

    for (size_t i = 0; i < other.cipherlength; i++)
        cipher[i] = other.cipher[i];

    textlength = other.textlength;
    cipherlength = other.cipherlength;
}

void Dossier::destroy()
{
    delete[] text;
    delete[] cipher;
}

Dossier::Dossier() {}

Dossier::Dossier(int* _text, size_t _textlength, Encoding* _cipher, size_t _cipherlength): textlength(_textlength), cipherlength(_cipherlength)
{
    text = new int[_textlength];

    for (size_t i = 0; i < _textlength; i++)
        text[i] = _text[i];

    cipher = new Encoding[_cipherlength];

    for (size_t i = 0; i < _cipherlength; i++)
        cipher[i] = _cipher[i];
}

Dossier::Dossier(const Dossier& other)
{
    copy(other);
}

Dossier& Dossier::operator=(const Dossier& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Dossier::~Dossier()
{
    destroy();
}

void Dossier::printText() const
{
    char* plaintext = new char[textlength];

    for (size_t i = 0; i < textlength; i++)
    {
        size_t j = 0;

        while (j < cipherlength && cipher[j].getCode() != text[i])
            j++;

        if (j < cipherlength)
            plaintext[i] = cipher[j].getChar();
    }

    std::cout << plaintext << std::endl;
    delete[] plaintext;
}

bool operator&&(const Dossier& d1, const Dossier& d2)
{
    for (size_t i = 0; i < d1.cipherlength; i++)
        for (size_t j = 0; j < d2.cipherlength; j++)
            if (d1.cipher[i].getChar() == d2.cipher[j].getChar() && d1.cipher[i].getCode() != d2.cipher[j].getCode())
                return false;

    return true;
}

Dossier operator+(const Dossier& d1, const Dossier& d2)
{
    if (!(d1 && d2))
        return Dossier();
    else
    {
        Dossier d;

        size_t sumtextlength = d1.textlength + d2.textlength;
        d.text = new int[sumtextlength];

        for (size_t i = 0; i < d1.textlength; i++)
            d.text[i] = d1.text[i];

        for (size_t i = 0; i < d2.textlength; i++)
            d.text[d1.textlength + i] = d2.text[i];

        size_t sumcipherlength = d1.cipherlength + d2.cipherlength;
        d.cipher = new Encoding[sumcipherlength];

        for (size_t i = 0; i < d1.cipherlength; i++)
            d.cipher[i] = d1.cipher[i];

        for (size_t i = 0; i < d2.cipherlength; i++)
            d.cipher[d1.cipherlength + i] = d2.cipher[i];

        d.textlength = sumtextlength;
        d.cipherlength = sumcipherlength;

        return d;
    }
}
