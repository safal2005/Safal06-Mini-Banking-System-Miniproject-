#include "BST.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Pause function
void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");  // clear screen after pausing
}

// Display menu
void displayMenu() {
    cout << "=====================================\n";
    cout << "|       MINI BANKING SYSTEM         |\n";
    cout << "=====================================\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Delete Account\n";
    cout << "5. Display All Accounts\n";
    cout << "6. View Account Details\n";
    cout << "7. Exit\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice: ";
    }

int main() {
    BST tree;
    tree.loadFromFile("accounts.txt");

    int choice;

    while (true) {
         system("cls");
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";

        if (choice == 1) {
            int accNum;
            string name;
            double balance;

            cout << "------ Create Account ------\n";
            cout << "Enter Account Number: ";
            cin >> accNum;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            tree.insert(Account(accNum, name, balance));
            tree.saveToFile("accounts.txt");

            cout << "\nAccount Created Successfully!\n";
            pauseScreen();
        }

        else if (choice == 2) {
            int accNum;
            double amount;

            cout << "------ Deposit ------\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            cout << "Enter Amount: ";
            cin >> amount;

            Account* acc = tree.search(accNum);
            if (acc) {
                    acc->deposit(amount);
                    tree.saveToFile("accounts.txt");
                    std::cout << "\nDeposit Successful!\n";
                    std::cout << "Updated Balance: Rs. " << acc->getBalance() << "\n";
                } else {
                cout << "\nAccount Not Found!\n";
            }

            pauseScreen();
        }

        else if (choice == 3) {
            int accNum;
            double amount;

            cout << "------ Withdraw ------\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            cout << "Enter Amount: ";
            cin >> amount;

            Account* acc = tree.search(accNum);
            if (acc) {
                if (acc->withdraw(amount)) {
                    tree.saveToFile("accounts.txt");
                    cout << "\nWithdrawal Successful!\n";
                    cout << "Remaining Balance: Rs. " 
                        << std::fixed << std::setprecision(2) 
                        << acc->getBalance() << "\n";
                } else {
                    cout << "\nInsufficient Balance!\n";
                }
            } else {
                cout << "\nAccount Not Found!\n";
            }

            pauseScreen();
        }

        else if (choice == 4) {
            int accNum;

            cout << "------ Delete Account ------\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            tree.remove(accNum);
            tree.saveToFile("accounts.txt");

            cout << "\nAccount Deleted (if existed).\n";
            pauseScreen();
        }

        else if (choice == 5) {
            cout << "------ All Accounts ------\n";
            tree.displayInorder();   // use your existing function
            pauseScreen();
        }

        else if (choice == 6) {
            int accNum;
            cout << "------ View Account ------\n";
            cout << "Enter Account Number: ";
            cin >> accNum;

            Account* acc = tree.search(accNum);
            if (acc) {
                acc->display();
            } else {
                cout << "\nAccount Not Found!\n";
            }

            pauseScreen();
        }

        else if (choice == 7) {
            tree.saveToFile("accounts.txt");
            cout << "\nExiting Program...\n";
            break;
        }

        else {
            cout << "\nInvalid Choice!\n";
            pauseScreen();
        }

        cout << "\n\n";
    }

    return 0;
}