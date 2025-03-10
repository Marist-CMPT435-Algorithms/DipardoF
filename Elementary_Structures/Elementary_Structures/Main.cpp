#include <iostream>
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"
#include "LinkedStack.hpp"
#include "DoublyLinkedQueue.hpp"

int main() {
    std::cout << "Starting Data Structure Tests\n";
    std::cout << "============================\n\n";

    // Run tests for each data structure
    testArrayStack();
    testArrayQueue();
    testLinkedStack();
    testDoublyLinkedQueue();

    std::cout << "All tests completed successfully!\n";
    return 0;
}