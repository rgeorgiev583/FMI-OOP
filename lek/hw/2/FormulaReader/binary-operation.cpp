/*
 * binary-operation.cpp
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#include "binary-operation.h"

void BinaryOperation::copy(const BinaryOperation& other)
{
	op = other.op;
	lhs = (Formula*) other.lhs->clone();
	rhs = (Formula*) other.rhs->clone();
}

void BinaryOperation::destroy()
{
	delete lhs;
	delete rhs;
}

BinaryOperation::BinaryOperation(char _op, const Formula* _lhs,
		const Formula* _rhs): op(_op), lhs((Formula*) _lhs->clone()),
		rhs((Formula*) _rhs->clone()) {}

BinaryOperation::BinaryOperation(const BinaryOperation& other)
{
	copy(other);
}

BinaryOperation& BinaryOperation::operator=(const BinaryOperation& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

BinaryOperation::~BinaryOperation()
{
	destroy();
}

double BinaryOperation::value() const
{
	switch (op)
	{
	case '+':
		return lhs->value() + rhs->value();

	case '-':
		return lhs->value() - rhs->value();

	case '*':
		return lhs->value() * rhs->value();

	case '/':
		return lhs->value() / rhs->value();

	case '<':
		return lhs->value() < rhs->value();

	case '=':
		return lhs->value() == rhs->value();
	}
}

void BinaryOperation::print(ostream& os = cout) const
{
	os << "( ";
	lhs->print();
	os << ' ' << op << ' ';
	rhs->print();
	os << " )";
}
