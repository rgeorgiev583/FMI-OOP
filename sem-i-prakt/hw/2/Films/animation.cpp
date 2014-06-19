#include "animation.h"

#include <cstring>

void Animation::copy(const Animation& other)
{
    animator = new char[strlen(other.animator) + 1];
    strcpy(animator, other.animator);
}

void Animation::destroy()
{
    delete[] animator;
}

Animation::Animation(): Film(), animator(NULL) {}

Animation::Animation(const char* _name, int _year = 0,
        const char* _animator = ""): Film(_name, _year)
{
    animator = new char[strlen(_animator) + 1];
    strcpy(animator, _animator);
}

Animation::Animation(const Animation& other)
{
    copy(other);
}

Animation& Animation::operator=(const Animation& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Animation::~Animation()
{
    destroy();
}

const char* Animation::getAnimator() const
{
    return animator;
}

void Animation::setAnimator(const char* _animator)
{
    animator = new char[strlen(_animator) + 1];
    strcpy(animator, _animator);
}
