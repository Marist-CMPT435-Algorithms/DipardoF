#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // helper methods
    Node* insertHelper(Node* node, int val);
    Node* deleteHelper(Node* node, int val);
    bool searchHelper(Node* node, int val);
    Node* findMin(Node* node);
    void inorderHelper(Node* node);
    void preorderHelper(Node* node);
    void postorderHelper(Node* node);
    void destroyHelper(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    // main operations
    void insert(int val);
    void remove(int val);
    bool search(int val);

    // traversals
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();

    bool isEmpty();
};

#endif