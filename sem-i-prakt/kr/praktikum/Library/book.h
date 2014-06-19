#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#define MAX_SIZE 1000

class Book
{
    char* name;
    size_t pageCount;

    void resize(size_t);
    void resize();
    void copy(const Book&);
    void destroy();
public:
    Book();
    Book(const char*, size_t);
    Book(const Book&);
    Book& operator=(const Book&);
    ~Book();

    const char* getName() const;
    size_t getPageCount() const;

    void setName(const char*);
    void setPageCount(size_t);

    friend bool operator<(const Book&, const Book&) const;
    friend bool operator>(const Book&, const Book&) const;

    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);
};

#endif // BOOK_H_INCLUDED
