/*
 * cloneable.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

class Cloneable
{
public:
	virtual ~Cloneable() {};

	virtual Cloneable* clone() const = 0;
};

#endif /* CLONEABLE_H_ */
