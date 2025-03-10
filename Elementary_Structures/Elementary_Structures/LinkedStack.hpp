#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* top_node;
    size_t stack_size;

public:
    // Constructor
    LinkedStack() : top_node(nullptr), stack_size(0) {}

    // Destructor
    ~LinkedStack() {
        clear();
    }

    // Push an element onto the stack
    void push(const T& item) {
        Node* new_node = new Node(item);
        new_node->next = top_node;
        top_node = new_node;
        stack_size++;
    }

    // Pop an element from the stack
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        Node* temp = top_node;
        T item = temp->data;
        top_node = top_node->next;
        delete temp;
        stack_size--;
        return item;
    }

    // Peek at the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return top_node->data;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top_node == nullptr;
    }

    // Get the current size of the stack
    size_t size() const {
        return stack_size;
    }

    // Clear the stack
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Test function for LinkedStack
void testLinkedStack() {
    std::cout << "Testing Linked Stack:\n";

    LinkedStack<int> stack;

    // Test pushing elements
    std::cout << "Pushing elements...\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Test size
    std::cout << "Stack size: " << stack.size() << "\n";

    // Test peek
    std::cout << "Top element: " << stack.peek() << "\n";

    // Test popping elements
    std::cout << "Popping elements:\n";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << "\n";

    // Test empty stack operations
    try {
        stack.pop();
    }
    catch (const std::underflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }

    std::cout << "Linked Stack tests completed.\n\n";
}

#endif // LINKED_STACK_HPP