/*
===============================================================================
📌 CIRCULAR QUEUE IMPLEMENTATION IN C++ USING ARRAY
===============================================================================

✅ Features:
- Enqueue (push)
- Dequeue (pop)
- Check if circular queue is empty or full

🧠 Use case:
Efficient memory usage when regular queue reaches end.
*/

#include <iostream>
using namespace std;

class CircularQueue {
    int size;
    int* arr;
    int front, rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full at position " << rear << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
        cout << data << " enqueued at position " << rear << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << arr[front] << " dequeued from position " << front << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    int rearElement() {
        return (isEmpty() ? -1 : arr[rear]);
    }
};


int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.dequeue();
    cq.enqueue(30);
    cout << "Rear element: " << cq.rearElement() << endl;
    return 0;
}

