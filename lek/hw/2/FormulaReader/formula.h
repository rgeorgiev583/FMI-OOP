/*
 * formula.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef FORMULA_H_
#define FORMULA_H_

#include "printable.h"
#include "cloneable.h"

class Formula: public Printable, public Cloneable
{
public:
	virtual ~Formula() {}

	virtual double value() const = 0;
	virtual void print(ostream& = cout) const = 0;
};

#endif /* FORMULA_H_ */
