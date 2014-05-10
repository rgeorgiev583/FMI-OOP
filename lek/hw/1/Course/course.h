#include <iostream>
#include "dstring.h"
#pragma once

class Course
{
    DynamicString title;
    char programme[30];
    int year, stream, weekday, start, length, place;

    void copy(const Course&);
    void destroy();

public:
    Course(const char* = NULL, const char* = NULL, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
    Course(const Course&);
    Course& operator=(const Course&);
    ~Course();

    const char* getTitle() const;
    const char* getProgramme() const;
    int getYear() const;
    int getStream() const;
    int getWeekday() const;
    int getStart() const;
    int getLength() const;
    int getPlace() const;

    void setProgramme(const char*);
    void setYear(int);
    void setStream(int);
    void setWeekday(int);
    void setStart(int);
    void setLength(int);
    void setPlace(int);

    friend ostream& operator<<(ostream& os, const Course& c);
    friend istream& operator>>(istream& is, Course& c);
};
