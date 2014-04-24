#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char name[100];
    int age;

public:

    Person(const char* name)
    {
        cout<<"DEBUG: Constructor"<<endl;
        if(strlen(name)>1)
            strcpy(this->name,name);
        else
            cout<<"ERROR: Invalid name!"<<endl;
    }

    Person(const int age)
    {
        cout<<"DEBUG: Constructor"<<endl;
        if(age>0)
            this->age=age;
        else
            cout<<"ERROR: Invalid age!"<<endl;
    }

    Person(const char* name,const int age)
    {
        cout<<"DEBUG: Constructor"<<endl;
        if(strlen(name)>1&&age>0)
        {
            strcpy(this->name,name);
            this->age=age;
        }
        else
            cout<<"ERROR: Invalid name and/or age!"<<endl;
    }

    Person(const Person& person)
    {
        cout<<"DEBUG: Copy constructor"<<endl;
        if(strlen(person.name)>1&&person.age>0)
        {
            strcpy(this->name,person.name);
            this->age=person.age;
        }
        else
            cout<<"ERROR: Invalid name and/or age!"<<endl;
    }

    ~Person()
    {
        cout<<"DEBUG: Destructor"<<endl;
    }

    char* get_name()
    {
        return name;
    }

    void set_name(const char* name)
    {
        if(strlen(name)>1)
            strcpy(this->name,name);
        else
            cout<<"ERROR: Invalid name!"<<endl;
    }

    int get_age()
    {
        return age;
    }

    void set_age(const int age)
    {
        if(age>0)
            this->age=age;
        else
            cout<<"ERROR: Invalid age!"<<endl;
    }

    void write()
    {
        cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
    }
};

int main()
{
    Person person("Pesho",19);
    person.write();
    person.set_name("Vancho");
    person.set_age(22);
    person.write();
    Person person2(person);
    person2.write();

	return 0;
}
