#include <iostream>
#include <fstream>
#include "BinarySearchTree.hpp"

using namespace std;

int main() {
    BinarySearchTree bst;

    // load data from file
    ifstream inputFile("input-numbers.txt");
    if (!inputFile) {
        cout << "Failed to open input file!" << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        bst.insert(num);
    }

    cout << "BST created from input file.\n";

    // test searches
    cout << "Searching for values...\n";
    cout << "Search 42: " << (bst.search(42) ? "Found" : "Not found") << endl;
    cout << "Search 13: " << (bst.search(13) ? "Found" : "Not found") << endl;
    cout << "Search 99: " << (bst.search(99) ? "Found" : "Not found") << endl;

    // display traversals
    cout << "\nInorder traversal: ";
    bst.inorderTraversal();

    cout << "Preorder traversal: ";
    bst.preorderTraversal();

    cout << "Postorder traversal: ";
    bst.postorderTraversal();

    // test removals
    cout << "\nRemoving 42...\n";
    bst.remove(42);

    cout << "New inorder traversal: ";
    bst.inorderTraversal();

    // just to be safe
    inputFile.close();

    return 0;
}