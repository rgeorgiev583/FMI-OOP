/*
 * contact-book.h
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#ifndef CONTACT_BOOK_H_
#define CONTACT_BOOK_H_

#include "contact.h"
#include "dictionary.cpp"

class ContactBook
{
	Dictionary<Name, Contact*> by_name;
	Dictionary<PhoneNumber, Contact*> by_phone_number;
	Dictionary<Id, Contact*> by_id;

	void copy(const ContactBook&);
	void destroy();
public:
	ContactBook();
	ContactBook(const ContactBook&);
	ContactBook& operator=(const ContactBook&);
	~ContactBook();

	Contact findContact(const string&, CONTACT_FIELD_TYPE) const;

	Contact findContact(const Name&) const;
	Contact findContact(const PhoneNumber&) const;
	Contact findContact(const Id&) const;

	void addContact(const Contact&);
	void addContact(const Name&, const PhoneNumber&, const Id&);

	bool removeContact(const string&, CONTACT_FIELD_TYPE);
	bool removeContact(const Name&);
	bool removeContact(const PhoneNumber&);
	bool removeContact(const Id&);

	void print(ostream&, CONTACT_FIELD_TYPE) const;

	friend ostream& operator<<(ostream&, const ContactBook&);
};

#endif /* CONTACT_BOOK_H_ */
