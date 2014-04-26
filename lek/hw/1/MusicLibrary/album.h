#include "dynarray.cpp"
#include "song.h"
#pragma once

class Album
{
    char title[100];
    DynamicArray<Song> songlist;

    void setTitle(const char*);
public:
    // конструктори:
    Album(char*);
    Album(char*, const DynamicArray<Song>&);

    // селектори:
    size_t getLength() const;
    const char* getArtist() const;
    const Song* findSong(const char*) const;

    // мутатори:
    void deleteDuplicates();

    // операции:
    void print() const;
    void detectAndRedirectCovers(const Album&);
};
