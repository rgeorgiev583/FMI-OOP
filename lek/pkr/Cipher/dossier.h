#include "encoding.h"
#pragma once

class Dossier
{
    int* text;
    size_t textlength;
    Encoding* cipher;
    size_t cipherlength;

    void copy(const Dossier&);
    void destroy();
public:
    Dossier();
    Dossier(int*, size_t, Encoding*, size_t);
    Dossier(const Dossier&);
    Dossier& operator=(const Dossier&);
    ~Dossier();

    void printText() const;

    friend bool operator&&(const Dossier&, const Dossier&);
    friend Dossier operator+(const Dossier&, const Dossier&);
};
