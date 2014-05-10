#pragma once

class Song
{
    char title[100], artist[100];
    int year;
    size_t length;  // в секунди
    Song* original; // само ако е кавър, а ако е оригинал, приема стойност NULL

public:
    // конструктори:
    Song();
    Song(const char*);
    Song(const char*, const char*, int = 0, size_t = 0);
    Song(const char*, const char*, Song*, int = 0, size_t = 0);

    // селектори:
    const char* getTitle() const;
    const char* getArtist() const;
    int getYear() const;
    size_t getLength() const;
    const Song* getOriginal() const;

    // мутатори:
    void setTitle(const char*);
    void setArtist(const char*);
    void setYear(int);
    void setLength(size_t);
    void setOriginal(Song*);

    // операции:
    void print() const;
    bool isEqual(const Song&) const;
    bool operator==(const Song&) const;
    bool operator!=(const Song&) const;
};
