#include "Account.h"
#include <iomanip>
#include<iostream>

using namespace std;

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





void Account::display() {
    std::cout << std::left << std::setw(12) << accountNumber
              << std::left << std::setw(20) << name
              << std::right << std::setw(12)
              << "Rs. " << std::fixed << std::setprecision(2) << balance
              << "\n";
}