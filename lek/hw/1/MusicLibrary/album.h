#include "llist.cpp"
#include "song.h"
#pragma once

class Album
{
    char title[100];
    LinkedList<Song> songlist;
    char* findbuf_title;
    Song* findbuf_lastfound;

    void copy(const Album&);
    void destroy();
    void setTitle(const char*);
public:
    // конструктори:
    Album(char*);
    Album(char*, const LinkedList<Song>&);
    Album(const Album&);
    Album& operator=(const Album&);
    ~Album();

    // селектори:
    size_t getLength() const;
    const char* getArtist() const;
    const Song* findSong(const char*) const;
    const Song* findNextSong() const;

    // мутатори:
    void
    void deleteDuplicates();

    // операции:
    void print() const;
    void detectAndRedirectCovers(const Album&);
};
