#include "BinarySearchTree.hpp"

// constructor
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// destructor
BinarySearchTree::~BinarySearchTree() {
    destroyHelper(root);
}

// cleanup memory
void BinarySearchTree::destroyHelper(Node* node) {
    if (node != nullptr) {
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

// check if empty
bool BinarySearchTree::isEmpty() {
    return root == nullptr;
}

// insert wrapper
void BinarySearchTree::insert(int val) {
    root = insertHelper(root, val);
}

// actual insert logic
Node* BinarySearchTree::insertHelper(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }

    if (val < node->data) {
        node->left = insertHelper(node->left, val);
    }
    else if (val > node->data) {
        node->right = insertHelper(node->right, val);
    }

    // no duplicates
    return node;
}

// search wrapper
bool BinarySearchTree::search(int val) {
    return searchHelper(root, val);
}

// actual search
bool BinarySearchTree::searchHelper(Node* node, int val) {
    if (node == nullptr)
        return false;

    if (node->data == val)
        return true;

    if (val < node->data)
        return searchHelper(node->left, val);
    else
        return searchHelper(node->right, val);
}

// finds smallest value
Node* BinarySearchTree::findMin(Node* node) {
    if (node == nullptr)
        return nullptr;

    while (node->left != nullptr)
        node = node->left;

    return node;
}

// delete wrapper
void BinarySearchTree::remove(int val) {
    root = deleteHelper(root, val);
}

// actual deletion
Node* BinarySearchTree::deleteHelper(Node* node, int val) {
    if (node == nullptr)
        return nullptr;

    if (val < node->data) {
        node->left = deleteHelper(node->left, val);
    }
    else if (val > node->data) {
        node->right = deleteHelper(node->right, val);
    }
    else {
        // found the node

        // case 1: leaf node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // case 2: one child
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // case 3: two children
        else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
    }

    return node;
}

// inorder wrapper
void BinarySearchTree::inorderTraversal() {
    inorderHelper(root);
    std::cout << std::endl;
}

// left, root, right
void BinarySearchTree::inorderHelper(Node* node) {
    if (node != nullptr) {
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }
}

// preorder wrapper
void BinarySearchTree::preorderTraversal() {
    preorderHelper(root);
    std::cout << std::endl;
}

// root, left, right
void BinarySearchTree::preorderHelper(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
}

// postorder wrapper
void BinarySearchTree::postorderTraversal() {
    postorderHelper(root);
    std::cout << std::endl;
}

// left, right, root
void BinarySearchTree::postorderHelper(Node* node) {
    if (node != nullptr) {
        postorderHelper(node->left);
        postorderHelper(node->right);
        std::cout << node->data << " ";
    }
}