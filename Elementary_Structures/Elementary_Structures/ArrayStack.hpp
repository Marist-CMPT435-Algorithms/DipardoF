#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include <stdexcept>
#include <iostream>
#include <algorithm>
// EXPLANATION:
// I wanted to add the inintial array amount to the current array amount to save on space so I made the initial capacity to be 10 for test case purposes, 
// and would add 10 more indexes if there was any overflow. I did this because it was a simple approach with linear growth to the array and would not 
// take up too much memory. However the drawback to this approach is that it would have to resize frequently if the the size of the array were to increase dramatically.
template <typename T, size_t INITIAL_CAPACITY = 10>
class ArrayStack {
private:
    T* data;
    size_t capacity;
    size_t top_index;

    // Helper method to resize the array
    void resize() {
        // Growth strategy: Add the initial capacity
        size_t new_capacity = capacity + INITIAL_CAPACITY;

        // Allocate new array
        T* new_data = new T[new_capacity];

        // Copy existing elements
        std::copy(data, data + top_index, new_data);

        // Clean up old array
        delete[] data;

        // Update to new array
        data = new_data;
        capacity = new_capacity;

        std::cout << "Stack resized to capacity: " << capacity << std::endl;
    }

public:
    // Constructor
    ArrayStack() : capacity(INITIAL_CAPACITY), top_index(0) {
        data = new T[capacity];
    }

    // Destructor
    ~ArrayStack() {
        delete[] data;
    }

    // Copy constructor
    ArrayStack(const ArrayStack& other) : capacity(other.capacity), top_index(other.top_index) {
        data = new T[capacity];
        std::copy(other.data, other.data + top_index, data);
    }

    // Assignment operator
    ArrayStack& operator=(const ArrayStack& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            top_index = other.top_index;
            data = new T[capacity];
            std::copy(other.data, other.data + top_index, data);
        }
        return *this;
    }

    // Push an element onto the stack
    void push(const T& item) {
        if (isFull()) {
            resize();
        }
        data[top_index++] = item;
    }

    // Pop an element from the stack
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[--top_index];
    }

    // Peek at the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[top_index - 1];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top_index == 0;
    }

    // Check if the stack is full
    bool isFull() const {
        return top_index >= capacity;
    }

    // Get the current size of the stack
    size_t size() const {
        return top_index;
    }

    // Get the current capacity of the stack
    size_t getCurrentCapacity() const {
        return capacity;
    }

    // Clear the stack
    void clear() {
        top_index = 0;
    }
};

// Comprehensive test function for ArrayStack with dynamic resizing
void testArrayStack() {
    std::cout << "Testing Array-backed Stack with dynamic resizing:\n";
    std::cout << "==============================================\n";

    // Test 1: Basic initialization
    std::cout << "Test 1: Basic initialization\n";
    ArrayStack<int, 5> stack;  // Start with a small capacity of 5
    std::cout << "Initial capacity: " << stack.getCurrentCapacity() << "\n";
    std::cout << "Stack is empty: " << (stack.isEmpty() ? "true" : "false") << "\n\n";

    // Test 2: Push elements until automatic resizing
    std::cout << "Test 2: Testing overflow and automatic resizing\n";
    for (int i = 1; i <= 12; i++) {
        std::cout << "Pushing " << i * 10 << "... ";
        stack.push(i * 10);
        std::cout << "Stack size: " << stack.size()
            << ", Capacity: " << stack.getCurrentCapacity()
            << ", Is full: " << (stack.isFull() ? "true" : "false") << "\n";
    }
    std::cout << "\n";

    // Test 3: Verify all elements are intact after resizing
    std::cout << "Test 3: Verifying elements after resizing\n";
    std::cout << "Top element: " << stack.peek() << " (expected: 120)\n";
    std::cout << "Popping all elements: ";
    int expected = 120;
    for (int i = 0; i < 12; i++) {
        int value = stack.pop();
        std::cout << value << " ";
        if (value != expected) {
            std::cout << "\nError: Expected " << expected << " but got " << value << "\n";
        }
        expected -= 10;
    }
    std::cout << "\n";
    std::cout << "Stack is now empty: " << (stack.isEmpty() ? "true" : "false") << "\n\n";

    // Test 4: Testing underflow condition
    std::cout << "Test 4: Testing underflow condition\n";
    try {
        std::cout << "Attempting to pop from empty stack... ";
        stack.pop();
        std::cout << "Failed: No exception thrown!\n";
    }
    catch (const std::underflow_error& e) {
        std::cout << "Success: Caught expected exception: " << e.what() << "\n";
    }

    try {
        std::cout << "Attempting to peek at empty stack... ";
        stack.peek();
        std::cout << "Failed: No exception thrown!\n";
    }
    catch (const std::underflow_error& e) {
        std::cout << "Success: Caught expected exception: " << e.what() << "\n\n";
    }

    // Test 5: Push-pop alternation
    std::cout << "Test 5: Push-pop alternation\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Push " << i << ", ";
        stack.push(i);
    }
    std::cout << "\nCurrent size: " << stack.size() << "\n";

    for (int i = 1; i <= 3; i++) {
        std::cout << "Pop " << stack.pop() << ", ";
    }
    std::cout << "\nCurrent size: " << stack.size() << "\n";

    for (int i = 6; i <= 10; i++) {
        std::cout << "Push " << i << ", ";
        stack.push(i);
    }
    std::cout << "\nCurrent size: " << stack.size() << "\n";

    std::cout << "Remaining elements: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << "\n\n";

    // Test 6: Large number of pushes to test multiple resizes
    std::cout << "Test 6: Multiple resize operations\n";
    std::cout << "Pushing 50 elements...\n";
    for (int i = 1; i <= 50; i++) {
        stack.push(i);
        if (i % 10 == 0) {
            std::cout << "After " << i << " pushes - Size: " << stack.size()
                << ", Capacity: " << stack.getCurrentCapacity() << "\n";
        }
    }

    std::cout << "Final capacity after pushing 50 elements: " << stack.getCurrentCapacity() << "\n";
    std::cout << "Clearing the stack...\n";
    stack.clear();
    std::cout << "Stack size after clear: " << stack.size() << "\n\n";

    std::cout << "All ArrayStack tests completed successfully!\n";
    std::cout << "==============================================\n\n";
}

#endif // ARRAY_STACK_HPP