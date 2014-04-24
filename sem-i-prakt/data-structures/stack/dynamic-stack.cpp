#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    char* data;
    Node* next;

    Node(): data(NULL), next(NULL) {}

    Node(const char* s): next(NULL)
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Node(const char* s, Node* _next): next(_next)
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    ~Node()
    {
        delete[] data;
    }
};

class Stack
{
    Node* top;

    void copy(const Stack& s)
    {
        Node* last = NULL;

        for (Node* i = s.top; i; i=i->next)
        {
            Node* elem = new Node(i->data);

            if (last)
                last->next = elem;
            else
                top = elem;

            last = elem;
        }
    }

    void destroy()
    {
        while(pop());
    }
public:
    Stack(): top(NULL) {}

    Stack(const Stack& s)
    {
        copy(s);
    }

    Stack& operator=(const Stack& s)
    {
        if (this != &s)
        {
            destroy();
            copy(s);
        }

        return *this;
    }

    ~Stack()
    {
        destroy();
    }

    bool empty() const
    {
        return !top;
    }

    char* peek() const
    {
        char* s = NULL;
        if (!empty())
        {
            s = new char[strlen(top->data) + 1];
            strcpy(s, top->data);
        }
        return s;
    }

    void push(const char* s)
    {
        Node* newtop = new Node(s, top);
        top = newtop;
    }

    bool pop()
    {
        if (empty())
            return false;
        else
        {
            Node* newtop = top->next;
            delete top;
            top = newtop;
            return true;
        }
    }
};

int main()
{
    char* str;
    Stack s;
    s.push("asd");
    str = s.peek();
    cout<<"\""<<str<<"\""<<endl;
    Stack s1(s);
    s1.push("");
    cout<<"\""<<s1.peek()<<"\""<<endl;
    Stack s2;
    s2 = s1;
    s1.pop();
    cout<<"\""<<s1.peek()<<"\""<<endl;
    s1.pop();
    cout<<"\""<<s2.peek()<<"\""<<endl;
    s2.pop();
    cout<<"\""<<s2.peek()<<"\""<<endl;
    s2.pop();
    if(s1.empty())
        cout<<"s1 е празен!"<<endl;
    if(s2.empty())
        cout<<"s2 е празен!"<<endl;

	return 0;
}
