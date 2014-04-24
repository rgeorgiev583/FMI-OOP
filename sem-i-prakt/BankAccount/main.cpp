#include <iostream>
#include "bankacc.h"
using namespace std;

int main()
{
    BankAccount ba("Ivan Ivanov", 123456789, 50.25);
    cout << ba;
    cin >> ba;
    cout << ba;

	return 0;
}
