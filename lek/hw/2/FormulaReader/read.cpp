/*
 * read.cpp
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#include "read.h"

using std::cerr;
using std::endl;

double Read::value() const
{
	double input;
	*is >> input;
	if (!*is)
	{
		cerr << "ERROR: The number entered was not a (real) number!" << endl;
		return 0;
	}

	return input;
}
