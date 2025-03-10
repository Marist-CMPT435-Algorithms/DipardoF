#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include <stdexcept>
#include <iostream>

template <typename T, size_t CAPACITY = 100>
class ArrayQueue {
private:
    T data[CAPACITY];
    size_t front;
    size_t rear;
    size_t current_size;

public:
    // Constructor
    ArrayQueue() : front(0), rear(0), current_size(0) {}

    // Enqueue an element
    void enqueue(const T& item) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        data[rear] = item;
        rear = (rear + 1) % CAPACITY;
        current_size++;
    }

    // Dequeue an element
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T item = data[front];
        front = (front + 1) % CAPACITY;
        current_size--;
        return item;
    }

    // Peek at the front element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return current_size == 0;
    }

    // Check if the queue is full
    bool isFull() const {
        return current_size >= CAPACITY;
    }

    // Get the current size of the queue
    size_t size() const {
        return current_size;
    }

    // Clear the queue
    void clear() {
        front = 0;
        rear = 0;
        current_size = 0;
    }
};

// Test function for ArrayQueue
void testArrayQueue() {
    std::cout << "Testing Array-backed Queue:\n";

    ArrayQueue<int> queue;

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

    std::cout << "Array-backed Queue tests completed.\n\n";
}

#endif // ARRAY_QUEUE_HPP