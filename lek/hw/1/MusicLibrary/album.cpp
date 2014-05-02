#include <iostream>
#include <cstring>
#include "album.h"

void Album::setTitle(const char* _title)
{
    if (!_title || !strlen(_title))
    {
        std::cerr << "ERROR: No album title specified." << std::endl;
        strcpy(title, "(Unknown title)");
    }
    else if (strlen(_title) < 100)
        strcpy(title, _title);
    else
    {
        std::cerr << "ERROR: Album title specified is too long." << std::endl;
        strcpy(title, "(Title too long)");
    }
}

void copy(const Album& other)
{
    findbuf_title = new char[strlen(other.findbuf_title) + 1];
    strcpy(findbuf_title, other.findbuf_title);
}

void destroy()
{
    delete[] findbuf_title;
}

Album::Album(char* _title)
{
    setTitle(_title);
}

Album::Album(char* _title, const LinkedList<Song>& _songlist): songlist(_songlist)
{
    setTitle(_title);
}

Album::Album(const Album& other)
{
    copy(other);
}

Album& Album::operator=(const Album& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Album::~Album()
{
    destroy();
}

size_t Album::getLength() const
{
    size_t songcount = songlist.size(), albumlength = 0;

    for (size_t i = 0; i < songcount; i++)
        albumlength += songlist[i].getLength();

    return albumlength;
}

const char* Album::getArtist() const
{
    size_t songcount = songlist.size(), i = 0;
    char* artist = new char[100];
    strcpy(artist, songlist[0].getArtist());

    do
        i++;
    while (i < songcount && !strcmp(songlist[i].getArtist(), artist));

    if (i < songcount)
        strcpy(artist, "Various Artists");

    return artist;
}

const Song* Album::findSong(const char* title) const
{
    findbuf_title = new char[strlen(title) + 1];
    strcpy(findbuf_title, title);

    size_t songcount = songlist.size(), i = 0;
    Song* findbuf_lastfound = songlist

    while (i < songcount && strcmp(songlist[i].getTitle(), findbuf_title))
        i++;

    return i < songcount ? &songlist[i] : NULL;
}

const Song* Album::findNextSong() const
{
    findbuf_title = new char[strlen(title) + 1];
    strcpy(findbuf_title, title);

    size_t songcount = songlist.size(), i = findbuf_lastfoundpos;

    while (i < songcount && strcmp(songlist[i].getTitle(), findbuf_title))
        i++;

    return i < songcount ? &songlist[i] : NULL;
}

void Album::deleteDuplicates()
{
    size_t songcount = songlist.size();

    for (size_t i = 0; i < songcount - 1; i++)
        for (size_t j = i + 1; j < songcount; j++)
            if (songlist[i] == songlist[j])
            {
                songlist.pop_at(j);
                songcount--;
            }
}

void Album::detectAndRedirectCovers(const Album& other)
{
    size_t songcount = songlist.size();
    bool iscover = false;

    for (size_t i = 0; i < songcount - 1; i++)
    {
        Song* found = other.findSong(songlist[i].getTitle());
        iscover = found && found->getArtist() != songlist[i].getArtist() && found->getYear() < songlist[i].getYear();
    }

    if (iscover)
        for (size_t i = 0; i < songcount - 1; i++)
        {
            Song* found = other.findSong(songlist[i].getTitle());

            if (found && found->getArtist() != songlist[i].getArtist() && found->getYear() < songlist[i].getYear())
                songlist[i].setOriginal(found);
        }
}

void Album::print() const
{
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Album title: " << title << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    size_t songcount = songlist.size();

    for (size_t i = 0; i < songcount; i++)
        songlist[i].print();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
}
