#include <iostream>
#include <cstring>
#include "album.h"

FindBuffer::FindBuffer(): title(NULL) {}

FindBuffer::FindBuffer(const FindBuffer&): title(NULL) {}

FindBuffer& FindBuffer::operator=(const FindBuffer&)
{
    delete[] title;
    title = NULL;
    lastfound = LinkedListIterator<Song>();

    return *this;
}

FindBuffer::~FindBuffer()
{
    delete[] title;
}

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

Album::Album(char* _title)
{
    setTitle(_title);
}

Album::Album(char* _title, const LinkedList<Song>& _songlist): songlist(_songlist)
{
    setTitle(_title);
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
    findbuf.title = new char[strlen(title) + 1];
    strcpy(findbuf.title, title);
    findbuf.lastfound = NULL;
    return findNextSong();
}

const Song* Album::findNextSong() const
{
    LinkedListIterator<Song> i = findbuf.lastfound ? findbuf.lastfound : songlist.begin();

    while (i != songlist.end() && strcmp(i->getTitle(), findbuf.title))
        i++;

    return i;
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
