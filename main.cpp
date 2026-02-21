#include "BST.h"
#include <iostream>
#include <iomanip>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Pause helper
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Color helper (Windows only)
void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}

int main() {
    BST bank;
    bank.loadFromFile("accounts.txt");
    int choice;

    while (true) {
        // Optional: clear screen for each menu iteration
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << "\n=====================================\n";
        cout << "        MINI BANKING SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Delete Account\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear leftover input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 6) break;

        int accNum;
        string name;
        double amount;

        // Separator for operations
        cout << "\n----------------------------------\n";

        switch(choice) {
            case 1: // Create Account
                cout << "Enter Account Number: ";
                cin >> accNum;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> amount;

                if (amount < 0) {
                    setColor(12);
                    cout << "\n>>> INVALID INITIAL BALANCE <<<\n";
                    setColor(7);
                } else {
                    bank.insert(Account(accNum, name, amount));
                    setColor(10);
                    cout << "\n>>> ACCOUNT CREATED SUCCESSFULLY <<<\n";
                    setColor(7);
                }
                pause();
                break;

            case 2: // Deposit
                cout << "Enter Account Number to Deposit: ";
                cin >> accNum;
                cout << "Enter Amount: ";
                cin >> amount;
                {
                    Account* acc = bank.search(accNum);
                    if (acc) {
                        if (amount <= 0) {
                            setColor(12);
                            cout << "\n>>> INVALID AMOUNT <<<\n";
                            setColor(7);
                        } else {
                            acc->deposit(amount);
                            setColor(10);
                            cout << "\n>>> DEPOSIT SUCCESSFUL <<<\n";
                            setColor(7);
                            cout << left << setw(15) << "Acc Number"
                                 << setw(15) << "Name"
                                 << "Balance\n";
                            cout << "----------------------------------\n";
                            acc->display();
                        }
                    } else {
                        setColor(12);
                        cout << "\n>>> ACCOUNT NOT FOUND <<<\n";
                        setColor(7);
                    }
                    pause();
                }
                break;

            case 3: // Withdraw
                cout << "Enter Account Number to Withdraw: ";
                cin >> accNum;
                cout << "Enter Amount: ";
                cin >> amount;
                {
                    Account* acc = bank.search(accNum);
                    if (acc) {
                        if(amount <= 0) {
                            setColor(12);
                            cout << "\n>>> INVALID AMOUNT <<<\n";
                            setColor(7);
                        } else if(acc->withdraw(amount)) {
                            setColor(10);
                            cout << "\n>>> WITHDRAWAL SUCCESSFUL <<<\n";
                            setColor(7);
                        } else {
                            setColor(12);
                            cout << "\n>>> INSUFFICIENT BALANCE <<<\n";
                            setColor(7);
                        }
                        cout << left << setw(15) << "Acc Number"
                             << setw(15) << "Name"
                             << "Balance\n";
                        cout << "----------------------------------\n";
                        acc->display();
                    } else {
                        setColor(12);
                        cout << "\n>>> ACCOUNT NOT FOUND <<<\n";
                        setColor(7);
                    }
                    pause();
                }
                break;

            case 4: // Delete
                cout << "Enter Account Number to Delete: ";
                cin >> accNum;
                {
                    Account* acc = bank.search(accNum);
                    if (acc) {
                        bank.remove(accNum);
                        setColor(10);
                        cout << "\n>>> ACCOUNT DELETED <<<\n";
                        setColor(7);
                    } else {
                        setColor(12);
                        cout << "\n>>> ACCOUNT NOT FOUND <<<\n";
                        setColor(7);
                    }
                    pause();
                }
                break;

            case 5: // Display All
                cout << left << setw(15) << "Acc Number"
                     << setw(15) << "Name"
                     << "Balance\n";
                cout << "----------------------------------\n";
                bank.displayInorder();
                pause();
                break;

            default:
                setColor(12);
                cout << "\n>>> INVALID CHOICE <<<\n";
                setColor(7);
                pause();
        }
    }

    bank.saveToFile("accounts.txt");
    cout << "\nExiting System. Goodbye!\n";
    return 0;
}