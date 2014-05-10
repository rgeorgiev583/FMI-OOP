#include <iostream>
#include "course.h"

void Course::copy(const Course& other)
{
    title = new char[strlen(other.title)];
    strcpy(title, other.title);
    setProgramme(other.programme);
    setYear(other.year);
    setStream(other.stream);
    setWeekday(other.weekday);
    setStart(other.start);
    setLength(other.length);
    setPlace(other.place);
}

void destroy()
{
    delete[] title;
}

Course::Course(const char* _title = NULL, char* _programme = NULL, int _year = 0, int _stream = 0, int _weekday = 0, int _start = 0, int _length = 0, int _place = 0)
{
    title = new char[strlen(_title)];
    strcpy(title, _title);
    setProgramme(_programme);
    setYear(_year);
    setStream(_stream);
    setWeekday(_weekday);
    setStart(_start);
    setLength(_length);
    setPlace(_place);
}

Course::Course(const Course& other)
{
    copy(other);
}

Course& Course::operator=(const Course& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Course::~Course()
{
    destroy();
}

const char* getTitle() const
{
    return title;
}

const char* getProgramme() const
{
    return programme;
}

int getYear() const
{
    return year;
}

int getStream() const
{
    return stream;
}

int getWeekday() const
{
    return weekday;
}

int getStart() const
{
    return start;
}

int getLength() const
{
    return length;
}

int getPlace() const
{
    return place;
}

void setProgramme(const char* _programme)
{
    if (strlen(_programme) < 30)
        strcpy(programme, _programme);
    else
    {
        std::cerr << "ERROR: Programme title specified is too long." << std::endl;
        strcpy(programme, "(Programme title too long)");
    }
}

void setYear(int _year)
{
    if (year >= 0 && year <= 4)
        year = _year;
    else
    {
        std::cerr << "ERROR: Year number must be between 0 and 4 (where 0 stands for elective course)." << std::endl;
        year = 0;
    }
}

void setStream(int _stream)
{
    if (stream >= 0 && stream <= 2)
        stream = _stream;
    else
    {
        std::cerr << "ERROR: Stream must be a number between 0 and 2 (where 0 stands for elective course)." << std::endl;
        stream = 0;
    }
}

void setWeekday(int _weekday)
{
    if (weekday >= 1 && weekday <= 6)
        weekday = _weekday;
    else
    {
        std::cerr << "ERROR: Weekday must be a number between 1 and 6." << std::endl;
        weekday = 1;
    }
}

void setStart(int _start)
{
    if (start >= 7 && start <= 20)
        start = _start;
    else
    {
        std::cerr << "ERROR: Start hour must be a number between 7 and 20." << std::endl;
        start = 7;
    }

    if (start + length > 21)
    {
        std::cerr << "A course must finish at latest at 21 o'clock." << std::endl;
        start = 21 - length;
    }
}

void setLength(int _length)
{
    if (length >= 1 && length <= 6)
        length = _length;
    else
    {
        std::cerr << "ERROR: Length in hours must be a number between 1 and 6." << std::endl;
        length = 1;
    }

    if (start + length > 21)
    {
        std::cerr << "A course must finish at latest at 21 o'clock." << std::endl;
        start = 21 - length;
    }
}

void setPlace(int _place)
{
    if (place >= 1 && place <= 599)
        place = _place;
    else
    {
        std::cerr << "ERROR: Room number must be between 1 and 599." << std::endl;
        place = 1;
    }
}

ostream& operator<<(ostream& os, const Course& c)
{
    os << std::endl;
    os << "Course title: " << title << std::endl;

    if (programme != "")
        os << "Course is taught to " << programme << " students" << std::endl;
    else
        os << "This is an elective course" << std::endl;

    if (year >= 1)
        os << "Year number: " << year << std::endl;
    if (stream >= 1)
        os << "Stream number: " << stream << std::endl;

    os << "Weekday: " << weekday << std::endl;
    os << "Start hour: " << start << std::endl;
    os << "Length in hours: " << length << std::endl;
    os << "Room number: " << place << std::endl;
    os << std::endl;
}

istream& operator>>(istream& is, Course& c)
{
    is >> title;
    is.getline(programme, );
    is >>
}

int main()
{
    Course c("Object-Oriented Programming", "Computer Science", 1, 2, 5, 12, 15, 221);
    std::cout << c;
}
