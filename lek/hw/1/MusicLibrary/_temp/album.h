#include "llist.cpp"
#include "song.h"
#pragma once

struct FindBuffer
{
    char* title;
    LinkedListIterator<Song> lastfound;

    void destroy();
    FindBuffer();
    FindBuffer(const FindBuffer&);
    FindBuffer& operator=(const FindBuffer&);
    ~FindBuffer();
};

class Album
{
    char title[100];
    LinkedList<Song> songlist;
    FindBuffer findbuf;

    void setTitle(const char*);
public:
    // конструктори:
    Album(char*);
    Album(char*, const LinkedList<Song>&);

    // селектори:
    size_t getLength() const;
    const char* getArtist() const;
    const Song* findSong(const char*) const;
    const Song* findNextSong() const;

    // мутатори:
    void deleteDuplicates();

    // операции:
    void print() const;
    void detectAndRedirectCovers(const Album&);
};
