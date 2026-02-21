#include "Account.h"

Account::Account(int accNo, std::string accName, double initialBalance) {
    accountNumber = accNo;
    name = accName;
    balance = initialBalance;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::display() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: Rs. " << balance << std::endl;
}