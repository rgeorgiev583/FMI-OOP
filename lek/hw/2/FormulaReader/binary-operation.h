/*
 * binary-operation.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef BINARY_OPERATION_H_
#define BINARY_OPERATION_H_

#include "formula.h"

class BinaryOperation: public Formula
{
	char op;
	Formula *lhs, *rhs;

	void copy(const BinaryOperation&);
	void destroy();
public:
	BinaryOperation(char, const Formula*, const Formula*);
	BinaryOperation(const BinaryOperation&);
	BinaryOperation& operator=(const BinaryOperation&);
	~BinaryOperation();

	Cloneable* clone() const { return new BinaryOperation(*this); }

	double value() const;
	void print(ostream& = cout) const;
};

#endif /* BINARY_OPERATION_H_ */
