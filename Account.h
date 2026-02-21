#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
private:
    int accountNumber;
    std::string name;
    double balance;

public:
    // Constructor
    Account(int accNo, std::string accName, double initialBalance);

    // Getters
    int getAccountNumber() const;
    std::string getName() const;
    double getBalance() const;

    // Operations
    void deposit(double amount);
    bool withdraw(double amount);

    void display() const;
};

#endif