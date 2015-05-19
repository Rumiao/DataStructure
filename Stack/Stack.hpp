#ifndef STACK__HPP
#define STACK__HPP

template <typename T>
class Stack {
    private:
        Stack(const Stack&) {}              // Protect copy constructor
        void operator =(const Stack&) {}    // Protect assignment
    public:
        Stack() {}                          // Default constructor
        virtual ~Stack() {}                 // Base destructor

        // Reinitialize the stack. The user is responsible for
        // reclaiming the storage used by the stack elements.
        virtual void clear() = 0;

        // Push an element on the top of the stack
        // it: The element being pushed onto the stack
        virtual void push() = 0;

        // Remove the element at the top of the stack
        // Return:The element at the top of the stack
        virtual T pop() = 0;

        // Return: A copy of the top element
        virtual const T& topValue() const = 0;

        // Return: The number of elements in the stack
        virtual int length() = 0;
};

#endif
