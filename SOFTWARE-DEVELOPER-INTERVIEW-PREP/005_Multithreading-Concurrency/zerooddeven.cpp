/*
Problem 3: 1116. Print Zero Even Odd

Print "0" followed by even and odd numbers in alternating order using three threads.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int turn = 0; // 0 = zero, 1 = odd, 2 = even

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero() {
        for (int i = 1; i <= n; ++i) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return turn == 0; });
            cout << "0 ";
            if (i % 2 == 1) turn = 1;
            else turn = 2;
            cv.notify_all();
        }
    }

    void odd() {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return turn == 1; });
            cout << i << " ";
            turn = 0;
            cv.notify_all();
        }
    }

    void even() {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return turn == 2; });
            cout << i << " ";
            turn = 0;
            cv.notify_all();
        }
    }
};

int main() {
    int n = 5;
    ZeroEvenOdd zeroEvenOdd(n);

    thread t1(&ZeroEvenOdd::zero, &zeroEvenOdd);
    thread t2(&ZeroEvenOdd::even, &zeroEvenOdd);
    thread t3(&ZeroEvenOdd::odd, &zeroEvenOdd);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
