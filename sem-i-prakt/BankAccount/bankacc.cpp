#include <iostream>
#include <cstring>
#include "bankacc.h"
const int MAX_SIZE = 1000;

void BankAccount::shrink()
{
    char* oldname = name;
    name = new char[strlen(oldname) + 1];
    strcpy(name, oldname);
    delete[] oldname;
}

void BankAccount::copy(const BankAccount& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    iban = other.iban;
    amount = other.amount;
}

void BankAccount::destroy()
{
    delete[] name;
}

BankAccount::BankAccount(): name(NULL), iban(0), amount(0.0) {}

BankAccount::BankAccount(const char* _name, long _iban, double _amount = 0.0): iban(_iban), amount(_amount)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

BankAccount::BankAccount(const BankAccount& other)
{
    copy(other);
}

BankAccount& BankAccount::operator=(const BankAccount& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

BankAccount::~BankAccount()
{
    destroy();
}

std::istream& operator>>(std::istream& is, BankAccount& ba)
{
    delete[] ba.name;
    ba.name = new char[MAX_SIZE];
    is.getline(ba.name, MAX_SIZE);
    ba.shrink();
    is >> ba.iban;
    is >> ba.amount;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& ba)
{
    if (ba.name && *ba.name)
        os << "Name: " << ba.name << std::endl;
    if (ba.iban)
        os << "IBAN: " << ba.iban << std::endl;

    os << "Amount: " << ba.amount << std::endl;
}
