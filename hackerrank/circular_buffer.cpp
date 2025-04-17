#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t size)
        : buffer(size), capacity(size), back(0), front(0), full(false) {}

    void push(const T& item) {
        buffer[back] = item;
        back = (back + 1) % capacity;

        if (full) {
            front = (front + 1) % capacity;  // Overwrite oldest
        }

        full = back == front;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Buffer is empty");
        }

        T val = buffer[front];
        front = (front + 1) % capacity;
        full = false;
        return val;
    }

    bool isEmpty() const {
        return (!full && back == front);
    }

    bool isFull() const {
        return full;
    }

    size_t size() const {
        if (full)
            return capacity;

        if (back >= front)
            return back - tail;
        else
            return capacity + back - tail;
    }

    void print() const {
        std::cout << "Buffer contents: ";
        for (size_t i = 0, idx = front; i < size(); ++i, idx = (idx + 1) % capacity) {
            std::cout << buffer[idx] << " ";
        }
        std::cout << "\n";
    }

private:
    std::vector<T> buffer;
    size_t capacity;
    size_t back;
    size_t front;
    bool full;
};
