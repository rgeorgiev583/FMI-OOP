#include <iostream>
#pragma once

class BankAccount
{
    char* name;
    long iban;
    double amount;

    void shrink();
    void copy(const BankAccount&);
    void destroy();
public:
    BankAccount();
    BankAccount(const char*, long, double = 0.0);
    BankAccount(const BankAccount&);
    BankAccount& operator=(const BankAccount&);
    ~BankAccount();

    friend std::ostream& operator<<(std::ostream& os, const BankAccount& ba);
    friend std::istream& operator>>(std::istream& is, BankAccount& ba);
};
