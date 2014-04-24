#include <iostream>
#include <cstring>
#include "song.h"

Song::Song(): year(0), length(0), original(this)
{
    strcpy(title, "(Unknown title)");
    strcpy(artist, "(Unknown artist)");
}

Song::Song(char* _title): year(0), length(0), original(this)
{
    setTitle(_title);
    strcpy(artist, "(Unknown artist)");
}

Song::Song(char* _title, char* _artist, int _year = 0, size_t _length = 0): year(_year), length(_length), original(this)
{
    setTitle(_title);
    setArtist(_artist);
}

Song::Song(char* _title, char* _artist, Song* _original, int _year = 0, size_t _length = 0): year(_year), length(_length), original(_original)
{
    setTitle(_title);
    setArtist(_artist);
}

const char* Song::getTitle() const
{
    return title;
}

void Song::setTitle(const char* _title)
{
    if (!_title || !strlen(_title))
    {
        std::cerr << "ERROR: No song title specified." << std::endl;
        strcpy(title, "(Unknown title)");
    }
    else if (strlen(_title) < 100)
        strcpy(title, _title);
    else
    {
        std::cerr << "ERROR: Song title specified is too long." << std::endl;
        strcpy(title, "(Title too long)");
    }
}

const char* Song::getArtist() const
{
    return artist;
}

void Song::setArtist(const char* _artist)
{
    if (!_artist || !strlen(_artist))
    {
        std::cerr << "ERROR: No artist name specified." << std::endl;
        strcpy(artist, "(Unknown artist)");
    }
    else if (strlen(_artist) < 100)
        strcpy(artist, _artist);
    else
    {
        std::cerr << "ERROR: Artist name specified is too long." << std::endl;
        strcpy(artist, "(Artist name too long)");
    }
}

int Song::getYear() const
{
    return year;
}

void Song::setYear(int _year)
{
    year = _year;
}

size_t Song::getLength() const
{
    return length;
}

void Song::setLength(size_t _length)
{
    length = _length;
}

const Song* Song::getOriginal() const
{
    return original;
}

void Song::setOriginal(const Song* _original)
{
    original = _original;
}

bool Song::isEqual(const Song& other) const
{
    return !strcmp(title, other.title) && !strcmp(artist, other.artist) && year == other.year && length == other.length;
}

bool Song::operator==(const Song& other) const
{
    return isEqual(other);
}

void Song::print() const
{
    std::cout << std::endl;
    std::cout << "Song title: " << title << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Length (in seconds): " << length << std::endl;
    std::cout << "Length (HH:MM:SS): " << length / 3600 << ':' << (length / 60) % 60 << ':' << length % 60 << std::endl;
    std::cout << "Original: " << (original != this ? original->title : "(Self)") << std::endl;
    std::cout << std::endl;
}
