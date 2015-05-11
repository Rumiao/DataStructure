#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "list.hpp"

/* linked list implementation */

const int defaultSize = 100;

void Assert(bool val, std::string message) {            // If val is not true, send a failed message and exit
    if (!val) {
        std::cout << "Assertion Failed: " << message << std::endl;
        exit(-1);
    }
}

template <typename T>
class Link {            // Singly linked list node
    public:
        T element;      // Value for this node
        Link* next;     // Pointer to next node in list

        Link(Link* nextval = 0) {    // Constructor
            next = nextval;
        }
        Link(const T& elemval, Link* nextval = 0) {
            element = elemval;
            next = nextval;
        }
};

template <typename T>
class LList : public List<T> {
    private:
        Link<T>* head;              // Pointer to list header
        Link<T>* tail;              // Pointer to last element
        Link<T>* curr;              // Access to current element
        int listSize;               // Size of list

        void init() {               // Intialization helper method
            curr = head = tail = new Link<T>;
            listSize = 0;
        }

        void removeAll() {          // Return link nodes to free store
            while (head != 0) {
                curr = head;
                head = head->next;
                delete curr;
            }
        }

    public:
        LList(int size = defaultSize) { init(); }           // Constructor
        ~LList() { removeAll(); }                           // Destructor

        void print() const;                                 // Print list contents

        void clear() { removeAll(); init(); }               // Clear list

        void insert(const T& it) {                          // Insert "it" at current position
            curr->next = new Link<T>(it, curr->next);
            if (tail == curr) tail = curr->next;
            ++listSize;
        }

        void append(const T& it) {                          // Append "it" to list
            tail = tail->next = new Link<T>(it, 0);
            ++listSize;
        }

        T remove() {                                        // Remove and return current element
            Assert(curr->next != 0, "No element");
            T it = curr->next->element;                     // Remember value
            Link<T>* ltemp = curr->next;                    // Remember link node
            if (tail == curr->next) {                       // Reset tail
                tail = curr;
            }
            curr->next = curr->next->next;                  // Remove from list
            delete ltemp;                                   // Reclaim space
            --listSize;                                     // Decrement the size
            return it;
        }

        void moveToStart() {                                // Place curr at list start
            curr = head;
        }

        void moveToEnd() {                                  // Place curr at list end
            curr = tail;
        }

        void prev() {                                       // Move curr one step left, no change if already at front
            if (curr == head) {
                return;
            }
            Link<T>* temp = head;
            while (temp->next != curr) {
                temp = temp->next;
            }
            curr = temp;
        }

        void next() {                                       // Move curr one step right, no change if already at end
            if (curr != tail) {
                curr = curr->next;
            }
        }

        int length() const {                                // Return length
            return listSize;
        }

        int currPos() const {                               // Return the position of the current element
            Link<T>* temp = head;
            int i = 0;
            for (; temp != curr; ++i) {
                temp = temp->next;
            }
            return i;
        }

        void moveToPos(int pos) {                           // Move down list to "pos" position
            Assert((pos >= 0) && (pos <= listSize), "Position out of range");
            curr = head;
            for (int i = 0; i < pos; ++i) {
                curr = curr->next;
            }
        }

        const T& getValue() const {                         // Return current element
            Assert(curr->next != 0, "No value");
            return curr->next->element;
        }
};

