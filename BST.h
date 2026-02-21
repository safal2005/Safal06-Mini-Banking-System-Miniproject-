#ifndef BST_H
#define BST_H

#include "Account.h"

class BST {
private:
    // Node structure inside BST
    struct Node {
        Account data;
        Node* left;
        Node* right;

        Node(Account acc) : data(acc), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Recursive helper functions
    Node* insertRec(Node* node, Account acc);
    Node* searchRec(Node* node, int accountNumber);
    Node* deleteRec(Node* node, int accountNumber);
    void inorderRec(Node* node) const;

public:
    BST();  // Constructor

    void insert(Account acc);
    Account* search(int accountNumber);
    void remove(int accountNumber);
    void displayInorder() const;
};

#endif