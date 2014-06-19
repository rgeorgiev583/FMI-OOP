/*
 * conditional.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef CONDITIONAL_H_
#define CONDITIONAL_H_

#include "formula.h"

class Conditional: public Formula
{
	Formula *condition, *result, *otherwise;

	void copy(const Conditional&);
	void destroy();
public:
	Conditional(Formula*, Formula*, Formula*);
	Conditional(const Conditional&);
	Conditional& operator=(const Conditional&);
	~Conditional();

	Cloneable* clone() const { return new Conditional(*this); }

	double value() const;
	void print(ostream& = cout) const;
};

#endif /* CONDITIONAL_H_ */
