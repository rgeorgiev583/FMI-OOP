#ifndef IFILM_H_INCLUDED
#define IFILM_H_INCLUDED

class IFilm
{
public:
    virtual const char* getName() const = 0;
    virtual int getShootingYear() const = 0;
    virtual void setName(const char*) = 0;
    virtual void setShootingYear(int) = 0;
    virtual ~IFilm();
};

#endif // IFILM_H_INCLUDED
