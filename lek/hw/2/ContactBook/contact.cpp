/*
 * contact.cpp
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#include "contact.h"
using std::endl;


Name::Name(): string() {}

Name::Name(const string& str): string(str) {}

Name::Name(const char* s): string(s) {}

Name& Name::operator=(const string& str)
{
	return (Name&) string::operator=(str);
}

Name& Name::operator=(const char* s)
{
	return (Name&) string::operator=(s);
}

Name& Name::assign(const string& str)
{
	return (Name&) assign(str);
}

Name& Name::assign(const char* s)
{
	return (Name&) assign(s);
}


PhoneNumber::PhoneNumber(): string() {}

PhoneNumber::PhoneNumber(const string& str): string()
{
	assign(str);
}

PhoneNumber::PhoneNumber(const char* s): string()
{
	assign(s);
}

PhoneNumber& PhoneNumber::operator=(const string& str)
{
	if (&str != this)
		assign(str);

	return *this;
}

PhoneNumber& PhoneNumber::operator=(const char* s)
{
	assign(s);
	return *this;
}

PhoneNumber& PhoneNumber::assign(const string& str)
{
	size_t len = str.length();

	if (len <= 10 && str[0] == '0' && str[1] >= '1' && str[1] <= '9')
	{
		size_t i = 0;

		while (i < len && str[i] >= '0' && str[i] <= '9')
			i++;

		if (i == len)
			return (PhoneNumber&) string::assign(str);
	}

	return *this;
}

PhoneNumber& PhoneNumber::assign(const char* s)
{
	assign(string(s));
	return *this;
}


Id::Id(): string() {}

Id::Id(const string& str): string(str) {}

Id::Id(const char* s): string(s) {}

Id& Id::operator=(const string& str)
{
	return (Id&) string::operator=(str);
}

Id& Id::operator=(const char* s)
{
	return (Id&) string::operator=(s);
}

Id& Id::assign(const string& str)
{
	return (Id&) assign(str);
}

Id& Id::assign(const char* s)
{
	return (Id&) assign(s);
}


Contact::Contact() {}

Contact::Contact(
		const Name& _name, const PhoneNumber& _phone_number, const Id& _id):
		name(_name), phone_number(_phone_number), id(_id) {}

ostream& operator<<(ostream& os, const Contact* pc)
{
	if (pc)
	{
		os << "Name: " << pc->name << endl;
		os << "Phone number: " << pc->phone_number << endl;
		os << "ID: " << pc->id << endl;
	}

	return os;
}

ostream& operator<<(ostream& os, const Contact& c)
{
	return operator<<(os, &c);
}
