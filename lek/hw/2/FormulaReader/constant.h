/*
 * constant.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "formula.h"

class Constant: public Formula
{
	double number;

public:
	Constant(): number(0) {}
	Constant(double _value): number(_value) {}

	Cloneable* clone() const { return new Constant(*this); }

	double value() const { return number; }
	void print(ostream& os = cout) const { os << number; }
};

#endif /* CONSTANT_H_ */
