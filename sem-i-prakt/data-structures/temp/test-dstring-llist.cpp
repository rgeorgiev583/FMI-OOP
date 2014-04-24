#include <iostream>
#include "dstring.h"
#include "llist.cpp"

using namespace std;
typedef DynamicString String;
typedef LinkedList<String> StringList;

int main()
{
    String ds = "cum";
    cout << ds << endl;
    getline(cin, ds);
    cout << ds << endl;
    cout << ds.size() << endl;
    ds[2]='c';
    StringList ls;
    ls.push_back(ds);
    ls.push_back("shit");
    for(int i = 0; i < ls.size(); i++)
        cout << ls[i] << endl;
    ls.pop_front();
    cout << ls.size() << endl;

    return 0;
}
