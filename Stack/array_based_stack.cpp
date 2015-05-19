#include <iostream>
#include <string>
#include <cstdlib>
#include "Stack.hpp"

void Assert(bool val, std::string message) {
    if (!val) {
        std::cout << message;
        exit(-1);
    }
}

template <typename T>
class AStack: public Stack<T> {
    private:
        int max_size;
        int top;
        T* list_array;

    public:
        AStack(int size = 100) {
            max_size = size;
            top = 0;
            list_array = new T[size];
        }

        ~AStack() {
            delete [] list_array;
        }

        void clear() {
            top = 0;
        }

        void push(const T& it) {
            Assert(top != max_size, "Stack is full!");
            list_array[top++] = it;
        }

        T pop() {
            Assert(top != 0, "Stack is empty!");
            return list_array[--top];
        }

        const T& topValue() const {
            Assert(top != 0, "Stack is empty!");
            return list_array[top - 1];
        }

        int length() const {
            return top;
        }
};

