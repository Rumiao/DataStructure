#include <iostream>
#include <cstdlib>
#include <string>
#include "Stack.hpp"

/* Linked stack implementation */

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
        Link(Link* nextval = 0) { next = nextval; }
        Link(const T& element_val, Link* nextval = 0) {
            element = element_val;
            next = nextval;
        }
};


template <typename T>
class LStack : public Stack<T> {
    private:
        Link<T> * top;
        int size;

    public:
        LStack(int sz = 100) {
            top = 0;
            size = 0;
        }

        ~LStack() { clear(); }

        void clear() {
            while (top != 0) {
                Link<T>* temp = top;
                top = top->next;
                delete temp;
            }
            size = 0;
        }

        void push(const T& it) {
            top = new Link<T>(it, top);
            ++size;
        }

        T pop() {
            Assert(top != 0, "Stack is empty!");
            T it = top->element;
            Link<T>* ltemp = top->next;
            delete top;
            top = ltemp;
            --size;
            return it;
        }

        const T& topValue() const {
            Assert(top != 0, "Stack is empty!");
            return top->element;
        }

        int length() const {
            return size;
        }
};

