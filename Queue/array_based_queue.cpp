#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.hpp"

/* Array based queue implementation */

void Assert(bool val, std::string message) {
    if (!val) {
        std::cout << message << std::endl;
        exit(-1);
    }
}

template <typename T>
class AQueue : public Queue<T> {
    private:
        int maxSize;
        int front;
        int rear;
        T* listArray;

    public:
        AQueue(int size = 100) {
            maxSize = size + 1;
            rear = 0, front = 1;
            listArray = new T[maxSize];
        }

        ~AQueue() {
            delete [] listArray;
        }

        void clear() {
            rear = 0; front = 1;
        }

        void enqueue(const T& it) {
            Assert((rear + 2) % maxSize != front, "Queue is full!");
            rear = (rear + 1) % maxSize;
            listArray[rear] = it;
        }

        T dequeue() {
            Assert(length() != 0, "Queue is empty!");
            T it = listArray[front];
            front = (front + 1) % maxSize;
            return it;
        }

        const T& frontValue() const {
            Assert(length() != 0, "Queue is empty!");
            return listArray[front];
        }

        int length() const {
            return (rear + maxSize - front + 1) % maxSize;
        }
};
