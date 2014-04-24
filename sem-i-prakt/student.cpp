#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char* const name;

public:
    Student(const char* const _name): name(strcpy(new char[strlen(_name)+1],_name)){}

    void print()
    {
        cout<<name<<endl;
        cout<<strlen(name)<<endl;
    }
};

int main()
{
    char p[] = "ivan";
    Student s(p);
    s.print();
    *p='T';
    p[3]='a';
    s.print();
}
