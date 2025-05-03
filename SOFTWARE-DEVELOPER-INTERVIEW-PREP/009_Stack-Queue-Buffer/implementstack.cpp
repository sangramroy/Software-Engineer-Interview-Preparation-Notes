/*
===============================================================================
📌 STACK IMPLEMENTATION IN C++ USING ARRAY
===============================================================================

✅ Features:
- Push operation
- Pop operation
- Check if stack is empty or full
- Get the top element

🧠 Use case:
Follows LIFO (Last In First Out) structure.
*/

#include <iostream>
using namespace std;

class Stack {
    int size;
    int* arr;
    int top;

public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack is full.\n";
        } else {
            arr[++top] = data;
            cout << data << " pushed at position " << top << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    int getTop() {
        return (isEmpty() ? -1 : arr[top]);
    }
};


int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    st.pop();
    cout << "Top element: " << st.getTop() << endl;
    return 0;
}

