#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* elements;
    size_t capacity;
    size_t top_index;

public:
    // Constructor
    Stack(size_t initial_capacity = 10) : capacity(initial_capacity), top_index(0) {
        elements = new T[capacity];
    }

    // Destructor
    ~Stack() {
        delete[] elements;
    }

    // Copy constructor
    Stack(const Stack& other) : capacity(other.capacity), top_index(other.top_index) {
        elements = new T[capacity];
        for (size_t i = 0; i < top_index; i++) {
            elements[i] = other.elements[i];
        }
    }

    // Assignment operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] elements;
            capacity = other.capacity;
            top_index = other.top_index;
            elements = new T[capacity];
            for (size_t i = 0; i < top_index; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Push an element onto the stack
    void push(const T& item) {
        if (top_index >= capacity) {
            // Resize the array if it's full
            size_t new_capacity = capacity * 2;
            T* new_elements = new T[new_capacity];

            for (size_t i = 0; i < capacity; i++) {
                new_elements[i] = elements[i];
            }

            delete[] elements;
            elements = new_elements;
            capacity = new_capacity;
        }

        elements[top_index++] = item;
    }

    // Pop an element from the stack
    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot pop from an empty stack");
        }
        return elements[--top_index];
    }

    // Peek at the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Cannot peek at an empty stack");
        }
        return elements[top_index - 1];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top_index == 0;
    }

    // Get the current size of the stack
    size_t size() const {
        return top_index;
    }

    // Clear the stack
    void clear() {
        top_index = 0;
    }
};

// Test cases
void runTests() {
    std::cout << "Running stack tests...\n";

    // Test 1: Basic push and pop
    {
        Stack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        std::cout << "Test 1: ";
        if (stack.pop() == 3 && stack.pop() == 2 && stack.pop() == 1 && stack.isEmpty()) {
            std::cout << "PASSED\n";
        }
        else {
            std::cout << "FAILED\n";
        }
    }

    // Test 2: Exception handling
    {
        Stack<int> stack;
        std::cout << "Test 2: ";
        try {
            stack.pop();
            std::cout << "FAILED (should have thrown an exception)\n";
        }
        catch (const std::runtime_error&) {
            std::cout << "PASSED\n";
        }
    }

    // Test 3: Peek functionality
    {
        Stack<int> stack;
        stack.push(10);
        stack.push(20);

        std::cout << "Test 3: ";
        if (stack.peek() == 20 && stack.size() == 2) {
            std::cout << "PASSED\n";
        }
        else {
            std::cout << "FAILED\n";
        }
    }

    // Test 4: Resize functionality
    {
        Stack<int> stack(2);  // Initial capacity of 2
        for (int i = 0; i < 10; i++) {
            stack.push(i);
        }

        std::cout << "Test 4: ";
        if (stack.size() == 10 && stack.peek() == 9) {
            std::cout << "PASSED\n";
        }
        else {
            std::cout << "FAILED\n";
        }
    }

    // Test 5: Copy constructor
    {
        Stack<int> stack1;
        stack1.push(1);
        stack1.push(2);

        Stack<int> stack2(stack1);
        stack1.push(3);

        std::cout << "Test 5: ";
        if (stack2.size() == 2 && stack2.peek() == 2 && stack1.size() == 3) {
            std::cout << "PASSED\n";
        }
        else {
            std::cout << "FAILED\n";
        }
    }
}

int main() {
    runTests();
    return 0;
}