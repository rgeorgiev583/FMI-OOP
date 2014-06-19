/*
 * main.cpp
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#include <iostream>

#include "formula-parser.h"

using namespace std;

int main()
{
	cout << getClosingParenthesisPosition("3 / ( 2 * ( 1 + 3 ) ) + 5") << endl;
	Formula* formula = readFormula();
	formula->print();
	cout << endl;
	cout << formula->value() << endl;
	delete formula;
	return 0;
}
