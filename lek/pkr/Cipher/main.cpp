#include <iostream>
#include "dossier.h"
using namespace std;

int main()
{
    Encoding a[2] = {Encoding('a', 5), Encoding('b', 10)};
    int b[5] = {5, 10, 10, 5, 10};
	Dossier d1(b, 5, a, 2);
    d1.printText();

    Encoding c[3] = {Encoding('c', 2), Encoding('d', 3), Encoding('e', 4)};
    int d[4] = {2, 3, 2, 3};
	Dossier d2(d, 4, c, 3);
    d2.printText();

    Dossier dos = d1 + d2;
    dos.printText();

	return 0;
}
