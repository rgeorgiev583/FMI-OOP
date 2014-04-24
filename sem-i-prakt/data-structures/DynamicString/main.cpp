#include <iostream>
#include "dstring.h"
using namespace std;

int main()
{
    DynamicString ds = "what the fuck", ds1;
    cout << ds << endl;
    cout << ds.size() << endl;
    cout << ds.find("the") << endl;
    cout << (ds.find("the") == DynamicString::npos ? "not found" : "found") << endl;
    cout << (ds.find("them") == DynamicString::npos ? "not found" : "found") << endl;
    getline(cin, ds1);
    cout << ds1 << endl;
    cout << ds1.empty() << endl;

	return 0;
}
