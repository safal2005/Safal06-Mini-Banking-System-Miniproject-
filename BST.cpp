#include "BST.h"
#include <fstream>
#include <sstream>
#include <functional>
#include <iostream>
using namespace std;

// Save all accounts to a file (inorder)
void BST::saveToFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile) return;

    function<void(Node*)> saveInorder = [&](Node* node) {
        if (!node) return;
        saveInorder(node->left);
        // Replace spaces in name with underscores
        string safeName = node->data.getName();
        for (char &c : safeName) if (c == ' ') c = '_';
        outFile << node->data.getAccountNumber() << " " << safeName << " " << node->data.getBalance() << "\n";
        saveInorder(node->right);
    };

    saveInorder(root);
    outFile.close();
}

// Load accounts from a file
void BST::loadFromFile(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        int accNum;
        string name;
        double bal;
        if (iss >> accNum >> name >> bal) {
            // Restore spaces if underscores were used
            for (char &c : name) if (c == '_') c = ' ';
            insert(Account(accNum, name, bal));
        }
    }
    inFile.close();
}




// Constructor
BST::BST() {
    root = nullptr;
}

// Public insert function
void BST::insert(Account acc) {
    root = insertRec(root, acc);
}

BST::Node* BST::insertRec(Node* node, Account acc) {

    // Case 1: Empty position found
    if (node == nullptr) {
        return new Node(acc);
    }

    // Compare account numbers
    if (acc.getAccountNumber() < node->data.getAccountNumber()) {
        node->left = insertRec(node->left, acc);
    }
    else if (acc.getAccountNumber() > node->data.getAccountNumber()) {
        node->right = insertRec(node->right, acc);
    }
    else {
        // Duplicate account number (ignore or handle)
        std::cout << "Account number already exists!\n";
    }

    return node;
}

void BST::displayInorder() const {
    inorderRec(root);
}

void BST::inorderRec(Node* node) const {
    if (node == nullptr)
        return;

    inorderRec(node->left);
    node->data.display();
    inorderRec(node->right);
}

BST::Node* BST::searchRec(Node* node, int accountNumber) {

    if (node == nullptr)
        return nullptr;

    if (accountNumber == node->data.getAccountNumber())
        return node;

    if (accountNumber < node->data.getAccountNumber())
        return searchRec(node->left, accountNumber);
    else
        return searchRec(node->right, accountNumber);
}


Account* BST::search(int accountNumber) {

    Node* result = searchRec(root, accountNumber);

    if (result != nullptr)
        return &(result->data);

    return nullptr;
}

BST::Node* BST::deleteRec(Node* node, int accountNumber) {
    if (node == nullptr)
        return node;

    if (accountNumber < node->data.getAccountNumber()) {
        node->left = deleteRec(node->left, accountNumber);
    }
    else if (accountNumber > node->data.getAccountNumber()) {
        node->right = deleteRec(node->right, accountNumber);
    }
    else {
        // Node found

        // Case 1: No child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // Case 2: One child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        Node* temp = node->right;
        // Find inorder successor (smallest in right subtree)
        while (temp && temp->left != nullptr)
            temp = temp->left;

        node->data = temp->data; // Copy successor data
        node->right = deleteRec(node->right, temp->data.getAccountNumber());
    }

    return node;
}
void BST::remove(int accountNumber) {
    root = deleteRec(root, accountNumber);
}