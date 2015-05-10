#include <cassert>
#include "list.hpp"



/* Sequential list implementation */

const int defaultSize = 233;

template <typename T>
class AList : public List<T> {
    private:
        int maxSize;            // Maximum size of list
        int listSize;           // Number of list items now
        int curr;               // Position of current element
        T* listArray;           // Array holding list elements

    public:
        AList(int size = defaultSize) {  // Constructor
            maxSize = size;
            listSize = curr = 0;
            listArray = new T[maxSize];
        }

        ~AList() { delete [] listArray; }   // Destructor

        void clear() {
            delete [] listArray;            // Remove the array
            listSize = curr = 0;            // Reset the size
            listArray = new T[maxSize];     // Recreate array
        }

        void insert(const T& it) {          // Insert "it" at current position
            assert(listSize < maxSize, "List capacity exceeded");
            for (int i = listSize; i > curr; --i) {         // Shift elements up to make room
                listArray[i] = listArray[i - 1];
            }
            listArray[curr] = it;
            ++listSize;                     // Increment list size
        }

        void append(const T& it) {          // Append "it"
            assert(listSize < maxSize, "List capacity exceeded");
            listArray[listSize++] = it;
        }

        T remove() {
            assert((curr >= 0) && (curr < listSize), "No element");
            T it = listArray[curr];         // Copy the element
            for (int i = curr; i < listSize - 1; ++i) {     // Shift them down
                listArray[i] = listArray[i + 1];
            }
            --listSize;                     // Decrement size
            return it;
        }

        void moveToStart() { curr = 0; }            // Reset position
        void moveToEnd() { curr = listSize; }       // Set at end
        void prev() { if (curr != 0) --curr; }      // Back up
        void next() { if (curr < listSize) ++curr; }// Next

        int length() const { return listSize; }     // Return list size
        int currPos() const { return curr; }        // Return current position

        void moveToPos(int pos) {                   // Set current list position to "pos"
            assert((pos >= 0) && (pos <= listSize), "Pos out of range");
            curr = pos;
        }

        const T& getValue() const {                 // Return current element
            assert((pos >= 0) && (pos < listSize), "No current elements");
            return listArray[curr];
        }
};
