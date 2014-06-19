/*
 * conditional.cpp
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#include "conditional.h"

void Conditional::copy(const Conditional& other)
{
	condition = (Formula*) other.condition->clone();
	result = (Formula*) other.result->clone();
	otherwise = (Formula*) other.otherwise->clone();
}

void Conditional::destroy()
{
	delete condition;
	delete result;
	delete otherwise;
}

Conditional::Conditional(Formula* _condition, Formula* _result,
		Formula* _otherwise):
		condition((Formula*) _condition->clone()),
		result((Formula*) _result->clone()),
		otherwise((Formula*) _otherwise->clone()) {}

Conditional::Conditional(const Conditional& other)
{
	copy(other);
}

Conditional& Conditional::operator=(const Conditional& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Conditional::~Conditional()
{
	destroy();
}

double Conditional::value() const
{
	return condition->value() ? result->value() : otherwise->value();
}

void Conditional::print(ostream& os = cout) const
{
	os << "if ";
	condition->print();
	os << " then ";
	result->print();
	os << " else ";
	otherwise->print();
}
