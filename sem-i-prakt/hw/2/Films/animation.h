#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include "film.h"

class Animation: public Film
{
    char* animator;

    void copy(const Animation&);
    void destroy();
public:
    Animation();
    Animation(const char*, int = 0, const char* = "");
    Animation(const Animation&);
    Animation& operator=(const Animation&);
    ~Animation();

    const char* getAnimator() const;

    void setAnimator(const char*);
};

#endif // ANIMATION_H_INCLUDED
