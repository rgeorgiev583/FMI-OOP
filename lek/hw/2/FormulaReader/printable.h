/*
 * printable.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef PRINTABLE_H_
#define PRINTABLE_H_

#include <iostream>
using std::ostream;
using std::cout;

class Printable
{
public:
	virtual ~Printable() {}

	virtual void print(ostream& = cout) const = 0;
};

#endif /* PRINTABLE_H_ */
