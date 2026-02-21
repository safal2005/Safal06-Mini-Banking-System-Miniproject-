#include "Account.h"
#include <iomanip>

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
    std::cout << std::left << std::setw(15) << accountNumber
              << std::setw(15) << name
              << "Rs. " << balance << std::endl;
}