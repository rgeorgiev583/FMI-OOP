#include "llist.cpp"
#include "song.h"
#pragma once

class Album
{
    char title[100];
    LinkedList<Song> songlist;

    void setTitle(const char*);
    LinkedListIterator<Song> base_findSong(const char*) const;
public:
    // конструктори:
    Album();
    Album(char*);
    Album(char*, const LinkedList<Song>&);

    // селектори:
    size_t getLength() const;
    const char* getArtist() const;
    const Song* findSong(const char*) const;

    // мутатори:
    void appendSong(const Song&);
    void deleteSong(const char*);
    void deleteSong(const Song&);
    void deleteDuplicates();

    // операции:
    void print() const;
    void detectAndRedirectCovers(const Album&);
};
