#ifndef DOUBLY_LINKED_QUEUE_HPP
#define DOUBLY_LINKED_QUEUE_HPP
#include <stdexcept>
#include <iostream>

template <typename T>
class DoublyLinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;  // Added prev pointer for doubly-linked implementation
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* front_node;
    Node* rear_node;
    size_t queue_size;

public:
    // Constructor
    DoublyLinkedQueue() : front_node(nullptr), rear_node(nullptr), queue_size(0) {}

    // Destructor
    ~DoublyLinkedQueue() {
        clear();
    }

    // Enqueue an element
    void enqueue(const T& item) {
        Node* new_node = new Node(item);

        if (isEmpty()) {
            front_node = new_node;
            rear_node = new_node;
        }
        else {
            rear_node->next = new_node;
            new_node->prev = rear_node;  // Set prev pointer to current rear
            rear_node = new_node;
        }
        queue_size++;
    }

    // Dequeue an element
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        Node* temp = front_node;
        T item = temp->data;

        front_node = front_node->next;

        if (front_node == nullptr) {
            rear_node = nullptr;
        }
        else {
            front_node->prev = nullptr;  // Update prev pointer of new front
        }

        delete temp;
        queue_size--;
        return item;
    }

    // Peek at the front element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return front_node->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front_node == nullptr;
    }

    // Get the current size of the queue
    size_t size() const {
        return queue_size;
    }

    // Clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Print all elements in the queue (for testing)
    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node* current = front_node;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Test function for DoublyLinkedQueue
void testDoublyLinkedQueue() {
    std::cout << "Testing Doubly Linked Queue:\n";
    DoublyLinkedQueue<int> queue;

    // Test enqueuing elements
    std::cout << "Enqueuing elements...\n";
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Test size
    std::cout << "Queue size: " << queue.size() << "\n";

    // Test peek
    std::cout << "Front element: " << queue.peek() << "\n";

    // Test dequeuing elements
    std::cout << "Dequeuing elements:\n";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << "\n";

    // Test empty queue operations
    try {
        queue.dequeue();
    }
    catch (const std::underflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }

    std::cout << "Doubly Linked Queue tests completed.\n\n";
}

#endif // DOUBLY_LINKED_QUEUE_HPP