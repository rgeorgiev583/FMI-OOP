/*
 * read.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef READ_H_
#define READ_H_

#include "formula.h"

using std::istream;
using std::cin;

class Read: public Formula
{
	istream* is;

public:
	Read(istream& _is = cin): is(&_is) {}

	Cloneable* clone() const { return new Read(*this); }

	double value() const;
	void print(ostream& os = cout) const { os << "Read"; }
};

#endif /* READ_H_ */
