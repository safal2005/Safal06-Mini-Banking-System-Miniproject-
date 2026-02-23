# Mini Banking System

A console-based banking application I built in C++ that demonstrates how Binary Search Trees work in real-world applications. This was my mini project for the Data Structures and Algorithms course.

## 📋 What This Project Is About

I wanted to create something more than just a textbook example of BST. So I built a functional banking system where you can create accounts, deposit and withdraw money, and manage everything efficiently using a Binary Search Tree. The cool part? Searching for an account among hundreds takes only a few comparisons instead of checking every single one.

**Author:** Safal Bastola  
**Roll Number:** 06  
**Course:** Data Structures and Algorithms

## ✨ What You Can Do

- **Create Account**: Set up new bank accounts with account numbers, names, and starting balance
- **Deposit Money**: Add funds to any account and see the updated balance instantly
- **Withdraw Money**: Take out money (only if you have enough balance!)
- **Delete Account**: Remove accounts when needed - the BST reorganizes itself automatically
- **Display All Accounts**: See every account sorted by account number
- **View Account Details**: Look up specific accounts quickly
- **Data Persistence**: Everything saves automatically, so your data is there when you come back

## 🗂️ What's in This Repository

```
Mini-Banking-System/
├── Account.h              # Account class definition
├── Account.cpp            # How accounts actually work
├── BST.h                  # Binary Search Tree structure
├── BST.cpp                # All the BST magic happens here
├── main.cpp               # The main program you interact with
├── accounts.txt           # Where account data is saved
├── banking.exe            # Ready-to-run program
├── main.exe               # Alternative executable
├── report.pdf             # Complete project documentation
├── Abstract_Mini_Banking.txt  # Quick project summary
├── imagesforreport/       # Diagrams and screenshots
├── .vscode/               # My VS Code settings
└── README.md              # You're reading this!
```

## 📁 Understanding the Files

### The Core Files

#### `Account.h` and `Account.cpp`
These files handle everything about individual accounts. I created an Account class that stores the account number, name, and balance. It also has methods to deposit money, withdraw money (with balance checking), and display account info. I kept the data private to protect it from being changed accidentally.

#### `BST.h` and `BST.cpp`
This is where the Binary Search Tree lives. The BST manages all the accounts and keeps them organized by account number. When you search for an account, it doesn't check every single one - it uses the BST property to eliminate half the remaining accounts with each comparison. Pretty efficient!

I implemented all the classic BST operations:
- **Insert**: Adds new accounts in the right spot
- **Search**: Finds accounts super fast (O(log n) on average)
- **Delete**: Removes accounts and handles all three cases (no children, one child, two children)
- **Inorder Traversal**: Displays accounts in sorted order naturally

The file handling is also here - it saves all accounts to a text file and loads them back when you restart the program.

#### `main.cpp`
This is what you actually interact with. It shows the menu, takes your input, and calls the right functions from the Account and BST classes. I tried to keep it simple and focused on user experience - clear menus, input validation, and helpful messages.

### Data Storage

#### `accounts.txt`
This is where all your account data lives. It's a simple text file with one account per line:
```
1010 Safal 1500
2000 Ram 2000
33522 Hari 12000000
```

The format is: account number, name, and balance (separated by spaces). I had to replace spaces in names with underscores to make parsing easier, but the program handles that automatically.

### Ready to Run

#### `banking.exe` and `main.exe`
These are compiled versions ready to run on Windows. Just double-click and you're good to go! I compiled them using GCC with the C++11 standard.

### Documentation

#### `report.pdf`
This is the complete project report with everything - introduction, design, implementation details, algorithms, testing results, and conclusions. If you want to understand the project in depth, check this out.

#### `Abstract_Mini_Banking.txt`
A quick summary of what the project is about, perfect if you just want the highlights.

#### `imagesforreport/`
I put all the diagrams, flowcharts, and screenshots here. These help visualize how the system works.

## 🛠️ How It Works

### Why Binary Search Tree?

I chose BST because it's perfect for this kind of application. Here's why:
- Accounts stay sorted by account number automatically
- Searching is fast - O(log n) instead of O(n)
- Adding and removing accounts is efficient
- Displaying accounts in order is natural with inorder traversal

### Performance

| What You Do | How Fast (Average) | Worst Case |
|-------------|-------------------|------------|
| Find an account | O(log n) | O(n) |
| Create account | O(log n) | O(n) |
| Delete account | O(log n) | O(n) |
| Show all accounts | O(n) | O(n) |

The worst case happens if you create accounts in perfect order (like 1, 2, 3, 4...), which makes the tree unbalanced. In real use, account numbers are more random, so it stays balanced naturally.

### How I Built It

I used object-oriented programming to keep things organized:
- **Account class**: Knows how to manage itself (deposit, withdraw, display)
- **BST class**: Manages the collection of all accounts
- **Main program**: Handles user interaction

This separation made debugging so much easier. If something was wrong with deposits, I knew to check Account.cpp. If searching wasn't working, I'd look at BST.cpp.

## 🚀 Getting Started

### What You Need

- A C++ compiler that supports C++11 (I used GCC with MinGW)
- Any operating system (Windows, Linux, or macOS)
- At least 2GB RAM (though it'll probably run on less)
- About 100MB of free space

### Compiling It Yourself

If you want to compile from source:

```bash
g++ -o banking.exe main.cpp Account.cpp BST.cpp -std=c++11
```

That's it! The `-std=c++11` flag is important because I used some C++11 features.

### Running the Program

On Windows, just run:
```bash
banking.exe
```

On Linux or Mac:
```bash
./banking.exe
```

Or just double-click the executable file.

## 📖 How to Use It

When you start the program, you'll see a menu with 7 options. Here's what each one does:

### 1. Create Account
You'll be asked for:
- Account number (make it unique!)
- Account holder's name
- Initial balance (how much money to start with)

The system checks if that account number already exists and won't let you create duplicates.

### 2. Deposit
Enter the account number and how much you want to deposit. The system finds the account, adds the money, and shows you the new balance.

### 3. Withdraw
Enter the account number and withdrawal amount. The system makes sure you have enough money before letting you withdraw. No overdrafts allowed!

### 4. Delete Account
Just enter the account number, and it's gone. The BST reorganizes itself automatically.

### 5. Display All Accounts
Shows every account in the system, sorted by account number. It's formatted in a nice table so it's easy to read.

### 6. View Account Details
Enter an account number to see all the details for just that account.

### 7. Exit
Saves everything and closes the program. Your data will be there next time!

### Example Session

```
=====================================
        MINI BANKING SYSTEM
=====================================
1. Create Account
2. Deposit
3. Withdraw
4. Delete Account
5. Display All Accounts
6. View Account Details
7. Exit
-------------------------------------
Enter your choice: 1

------ Create Account ------
Enter Account Number: 1001
Enter Name: John Doe
Enter Initial Balance: 5000

Account Created Successfully!

Press Enter to continue...
```

## 🧪 Testing

I tested this thing thoroughly! Here's what I checked:

- Creating accounts with different data (including edge cases)
- Depositing to accounts that exist and ones that don't
- Withdrawing with enough money and without enough money
- Deleting accounts in different positions in the tree
- Making sure accounts display in sorted order
- Closing and reopening to verify data persistence
- Trying to break it with invalid inputs
- Testing with names that have spaces

Everything works as expected. The BST operations are solid, file handling is reliable, and the interface is responsive.

## 🔧 What Could Be Better

I'm aware of some limitations:

1. **Unbalanced Tree Problem**: If you create accounts in sorted order (1, 2, 3, 4...), the tree becomes unbalanced and performance drops. A self-balancing tree like AVL would fix this.

2. **Console Only**: It's a text-based interface. A GUI would be nicer to use, but I wanted to focus on the data structure implementation first.

3. **Basic Features**: Real banks have transaction history, interest calculation, different account types, etc. This is a mini project, so I kept it simple.

4. **Single User**: Only one person can use it at a time. No concurrent access or user authentication.

5. **Text File Storage**: Works fine for this project, but a real database would be better for larger scale.

## 🔮 What I'd Add Next

If I continue working on this, here's what I'd add:

- [ ] Self-balancing tree (AVL or Red-Black) to guarantee performance
- [ ] Transaction history so you can see past deposits and withdrawals
- [ ] A proper GUI using Qt or something similar
- [ ] Database integration (SQLite would be perfect)
- [ ] Password protection for accounts
- [ ] Different account types (savings, checking, etc.)
- [ ] Transfer money between accounts
- [ ] Generate account statements
- [ ] Support for multiple users with different roles
- [ ] Interest calculation for savings accounts

## 📚 What I Learned

This project taught me a lot:

- **BST in Practice**: Understanding how BST works in theory vs. implementing it for a real application are very different things
- **Recursive Thinking**: BST operations are naturally recursive, and implementing them helped me understand recursion much better
- **File Handling**: Making data persistent isn't just a nice feature - it's essential for any real application
- **Modular Design**: Separating code into classes made everything easier to manage and debug
- **Testing Matters**: I found several bugs during testing that I wouldn't have caught otherwise
- **User Experience**: Even in a console app, clear menus and helpful messages make a big difference

## 📄 Documentation

For complete technical documentation, algorithms, design decisions, and detailed analysis, check out **report.pdf** in this repository. It includes:
- Full introduction and background
- System design and architecture
- Detailed implementation with algorithms
- Testing results and performance analysis
- Conclusions and future work

## 🤝 Want to Contribute?

This is an educational project, but if you have suggestions or find bugs, feel free to let me know! I'm always interested in learning better ways to do things.

## 👤 About Me

**Safal Bastola**  
Roll Number: 06  
Data Structures and Algorithms Course

This was my mini project where I got to apply what we learned in class to build something functional. It was challenging but really rewarding to see everything come together!

---

**Note**: This is a learning project built for educational purposes. It demonstrates BST implementation and basic banking operations, but doesn't include all the security and features you'd find in a production banking system.
