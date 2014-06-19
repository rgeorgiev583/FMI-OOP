/*
 * contact.h
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
using std::string;
using std::ostream;

enum CONTACT_FIELD_TYPE
{
	NAME,
	PHONE_NUMBER,
	ID
};

class Name: public string
{
public:
	Name();
	Name(const string&);
	Name(const char*);
	Name& operator=(const string&);
	Name& operator=(const char*);
	Name& assign(const string&);
	Name& assign(const char*);
};

class PhoneNumber: public string
{
public:
	PhoneNumber();
	PhoneNumber(const string&);
	PhoneNumber(const char*);
	PhoneNumber& operator=(const string&);
	PhoneNumber& operator=(const char*);
	PhoneNumber& assign(const string&);
	PhoneNumber& assign(const char*);
};

class Id: public string
{
public:
	Id();
	Id(const string&);
	Id(const char*);
	Id& operator=(const string&);
	Id& operator=(const char*);
	Id& assign(const string&);
	Id& assign(const char*);
};

class Contact
{
	Name name;
	PhoneNumber phone_number;
	Id id;

public:
	Contact();
	Contact(const Name&, const PhoneNumber&, const Id&);

	Name getName() const { return name; }
	PhoneNumber getPhoneNumber() const { return phone_number; }
	Id getId() const { return id; }

	void setPhoneNumber(const PhoneNumber& _phone_number)
			{ phone_number = _phone_number; }
	void setId(const Id& _id) { id = _id; }

	friend ostream& operator<<(ostream&, const Contact*);
	friend ostream& operator<<(ostream&, const Contact&);
};

#endif /* CONTACT_H_ */
