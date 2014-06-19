/*
 * main.cpp
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#include <iostream>
using namespace std;

#include "contact-book.h"

int main()
{
	/*Dictionary<string, string> wat;
	wat["wtf"] = "lmao";
	wat["omg"] = "lol";
	wat["foo"] = "bar";
	wat.print();*/
	ContactBook cb;
	cb.addContact("Ivan Petrov", "0899953295", "ivan.petrov@abv.bg");
	cb.addContact(Contact("Boris Simeonov", "0888888888", "bobby_b@gmail.com"));
	cb.addContact("Georgi Ivanov", "0899839523", "dark.magician.777@yahoo.com");
	cout << "ssdf" << endl;
	cout << cb;
	Contact gi = cb.findContact("Georgi Ivanov", NAME);
	cout << "------------" << endl;
	cout << gi;
	cb.removeContact(Name("Boris Simeonov"));
	cout << "------------" << endl;
	cout << cb;

	ContactBook cb1 = cb;
	Name name = "Asen Asenov";
	PhoneNumber phone_number = "0898828565";
	cout << "`" << phone_number << "`" << endl;
	Id id = "iamtheman@live.com";
	cb1.addContact(name, phone_number, id);
	cout << "------------" << endl;
	cb1.print(cout, PHONE_NUMBER);
	ContactBook cb2;
	cb2 = cb1;
	Contact aa = cb2.findContact(phone_number);
	cout << "------------" << endl;
	cout << aa;
	cout << "------------" << endl;
	cb2.addContact("Georgi Ivanov", "0899362432", "geo-iv@mail.bg");
	cout << cb2.findContact("dark.magician.777@yahoo.com", ID);
	cout << "------------" << endl;
    cout << cb2.findContact("geo-iv@mail.bg", ID);
	cout << "------------" << endl;
	cout << cb2.findContact(Name("Georgi Ivanov"));
	cout << "------------" << endl;
	cout << "~~~~~~~~~~~~" << endl;
	cb2.print(cout, ID);
	cout << "~~~~~~~~~~~~" << endl;
	cb2.removeContact(Name("Georgi Ivanov"));
	cout << cb2.findContact(Name("Georgi Ivanov"));
	cout << "~~~~~~~~~~~~" << endl;
	cb2.print(cout, ID);
	cout << "~~~~~~~~~~~~" << endl;

	return 0;
}
