#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.hpp"

/* Linked queue implementation */

void Assert(bool val, std::string message) {
    if (!val) {
        std::cout << message << std::endl;
        exit(-1);
    }
}

template <typename T>
class Link {
    public:
        T element;
        Link* next;

        Link() {
            next = 0;
        }

        Link(const T& elementVal, Link* nextVal) {
            element = elementVal;
            next = nextVal;
        }
};

template <typename T>
class LQueue : public Queue<T> {
    private:
        Link<T>* front;
        Link<T>* rear;
        int size;

    public:
        LQueue() {
            front = rear = new Link<T>();
            size = 0;
        }

        ~LQueue() {
            clear();
            delete front;
        }

        void clear() {
            while (front->next != 0) {
                rear = front;
                delete rear;
            }
            rear = front;
            size = 0;
        }

        void enqueue(const T& it) {
            rear->next = new Link<T>(it, 0);
            rear = rear->next;
            ++size;
        }

        T dequeue() {
            Assert(size != 0, "Queue is empty!");
            T it = front->next->element;
            Link<T>* ltemp = front->next;
            front->next = ltemp->next;
            if (rear == ltemp) rear = front;
            delete ltemp;
            --size;
            return it;
        }

        const T& frontValue() const {
            Assert(size != 0, "Queue is empty!");
            return front->next->element;
        }

        int length() const {
            return size;
        }
};

