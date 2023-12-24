#include <iostream>
using namespace std;


class Stack {
private:
    int max_size;
    int *stackArray;
    int top;

public:
    Stack(int size) : max_size(size), top(-1) {
        stackArray = new int[max_size];
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(int item) {
        if (top >= max_size - 1) {
            cout << "Stack Overflow" << std::endl;
        } else {
            top++;
            stackArray[top] = item;
            cout << "Pushed " << item << " into the stack" << std::endl;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow " << std::endl;
            return -1; // Return a default value indicating underflow
        } else {
            int item = stackArray[top];
            top--;
            cout << "Popped " << item << " from the stack" << std::endl;
            return item;
        }
    }
};

int main() {
    Stack stack(5); // Creating a stack with a maximum size of 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.push(6); // Attempting to push when the stack is full

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.pop(); // Attempting to pop when the stack is empty

    return 0;
}
