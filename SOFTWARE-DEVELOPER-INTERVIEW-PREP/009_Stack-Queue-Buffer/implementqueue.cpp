/*
===============================================================================
📌 LINEAR QUEUE IMPLEMENTATION IN C++ USING ARRAY
===============================================================================

✅ Features:
- Enqueue (push)
- Dequeue (pop)
- Check if queue is empty or full

🧠 Use case:
Follows FIFO (First In First Out) principle.
*/

#include <iostream>
using namespace std;

class Queue {
    int size;
    int* arr;
    int front, rear;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full.\n";
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            arr[rear] = data;
            cout << data << " enqueued at position " << rear << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << arr[front] << " dequeued from position " << front << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    int frontElement() {
        return (isEmpty() ? -1 : arr[front]);
    }
};


int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    cout << "Front element: " << q.frontElement() << endl;
    return 0;
}

