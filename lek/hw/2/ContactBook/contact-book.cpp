/*
 * contact-book.cpp
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#include "contact-book.h"

void ContactBook::copy(const ContactBook& other)
{
	Id* id = (Id*) other.by_id.begin_keys();
	Contact** contact = (Contact**) other.by_id.begin_values();

	while (id != other.by_id.end_keys() && contact != other.by_id.end_values())
	{
		if (*contact)
		{
			Contact* contact_copy = new Contact(**contact);
			by_name.insert((*contact)->getName(), contact_copy);
			by_phone_number[(*contact)->getPhoneNumber()] = contact_copy;
			by_id[*id] = contact_copy;
		}

		id++;
		contact++;
	}
}

void ContactBook::destroy()
{
	for (Contact** contact = (Contact**) by_id.begin_values();
			contact != by_id.end_values(); contact++)
		if (*contact)
			delete *contact;
}

ContactBook::ContactBook() {}

ContactBook::ContactBook(const ContactBook& other)
{
	copy(other);
}

ContactBook& ContactBook::operator=(const ContactBook& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

ContactBook::~ContactBook()
{
	destroy();
}

Contact ContactBook::findContact(
		const string& cf, CONTACT_FIELD_TYPE cft = NAME) const
{
	const Contact* const* contact;

	switch (cft)
	{
	case NAME:
		contact = by_name.find(cf);
		break;

	case PHONE_NUMBER:
		contact = by_phone_number.find(cf);
		break;

	case ID:
		contact = by_id.find(cf);
	}

	return contact && *contact ? **contact : Contact();
}

Contact ContactBook::findContact(const Name& name) const
{
	const Contact* const* contact = by_name.find(name);
	return contact && *contact ? **contact : Contact();
}

Contact ContactBook::findContact(const PhoneNumber& phone_number) const
{
	const Contact* const* contact = by_phone_number.find(phone_number);
	return contact && *contact ? **contact : Contact();
}

Contact ContactBook::findContact(const Id& id) const
{
	const Contact* const* contact = by_id.find(id);
	return contact && *contact ? **contact : Contact();
}

void ContactBook::addContact(const Contact& c)
{
	Contact* contact = new Contact(c);
	by_name.insert(c.getName(), contact);
	by_phone_number[c.getPhoneNumber()] = contact;
	by_id[c.getId()] = contact;
}

void ContactBook::addContact(
		const Name& name, const PhoneNumber& phone_number, const Id& id)
{
	Contact* contact = new Contact(name, phone_number, id);
	by_name.insert(name, contact);
	by_phone_number[phone_number] = contact;
	by_id[id] = contact;
}

bool ContactBook::removeContact(const string& cf, CONTACT_FIELD_TYPE cft = NAME)
{
	switch (cft)
	{
	case NAME:
		return removeContact(Name(cf));

	case PHONE_NUMBER:
		return removeContact(PhoneNumber(cf));

	case ID:
		return removeContact(Id(cf));
	}

	return false;
}

bool ContactBook::removeContact(const Name& name)
{
	Contact** contact_by_name = by_name.find(name);

	if (contact_by_name && *contact_by_name)
	{
		Contact* contact = *contact_by_name;
		Contact** contact_by_phone_number =
				by_phone_number.find((*contact_by_name)->getPhoneNumber());
		Contact** contact_by_id = by_id.find((*contact_by_name)->getId());
		bool success = true;

		if (contact_by_id && *contact_by_id)
		{
			Contact** next_contact_by_id = contact_by_id + 1;

			while (next_contact_by_id &&
					next_contact_by_id != by_id.end_values() &&
					(!*next_contact_by_id ||
					(*next_contact_by_id)->getName() != name))
				next_contact_by_id++;

			if (next_contact_by_id && next_contact_by_id != by_id.end_values()
					&& *next_contact_by_id)
				*contact_by_name = *next_contact_by_id;
			else
				success = success && by_name.erase(contact_by_name);

			success = success && by_id.erase(contact_by_id);
		}
		else
		{
			by_name.erase(contact_by_name);
			success = false;
		}

		success = contact_by_phone_number && *contact_by_phone_number ?
				success && by_phone_number.erase(contact_by_phone_number) :
				false;

		if (contact)
		{
			delete contact;
			return success;
		}
		else
			return false;
	}
	else
		return false;
}

bool ContactBook::removeContact(const PhoneNumber& phone_number)
{
	Contact** contact_by_phone_number = by_phone_number.find(phone_number);

	if (contact_by_phone_number && *contact_by_phone_number)
	{
		Contact* contact = *contact_by_phone_number;
		Contact** contact_by_name =
				by_name.find((*contact_by_phone_number)->getName());
		Contact** contact_by_id =
				by_id.find((*contact_by_phone_number)->getId());
		bool success = by_phone_number.erase(contact_by_phone_number);
		success = contact_by_name && *contact_by_name ?
				success && by_name.erase(contact_by_name) : false;
		success = contact_by_id && *contact_by_id ?
				success && by_id.erase(contact_by_id) : false;

		if (contact)
		{
			delete contact;
			return success;
		}
		else
			return false;
	}
	else
		return false;
}

bool ContactBook::removeContact(const Id& id)
{
	Contact** contact_by_id = by_id.find(id);

	if (contact_by_id && *contact_by_id)
	{
		Contact* contact = *contact_by_id;
		Contact** contact_by_name =
				by_name.find((*contact_by_id)->getName());
		Contact** contact_by_phone_number =
				by_phone_number.find((*contact_by_id)->getPhoneNumber());
		bool success = by_id.erase(contact_by_id);
		success = contact_by_name && *contact_by_name ?
				success && by_name.erase(contact_by_name) : false;
		success = contact_by_phone_number && *contact_by_phone_number ?
				success && by_phone_number.erase(contact_by_phone_number) :
				false;

		if (contact)
		{
			delete contact;
			return success;
		}
		else
			return false;
	}
	else
		return false;
}

void ContactBook::print(ostream& os = cout, CONTACT_FIELD_TYPE cft = NAME) const
{
	switch (cft)
	{
	case NAME:
		by_name.printValues(os);
		break;

	case PHONE_NUMBER:
		by_phone_number.printValues(os);
		break;

	case ID:
		by_id.printValues(os);
	}
}

ostream& operator<<(ostream& os, const ContactBook& cb)
{
	cb.print(os);
	return os;
}
