/*
Problem 2: 1115. Print FooBar Alternately

We need to print "foo" and "bar" alternately using two threads.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int turn = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 0; });
            cout << "foo ";
            turn = 1;
            cv.notify_all();
        }
    }

    void bar() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 1; });
            cout << "bar ";
            turn = 0;
            cv.notify_all();
        }
    }
};

int main() {
    int n = 5;
    FooBar fooBar(n);

    thread t1(&FooBar::foo, &fooBar);
    thread t2(&FooBar::bar, &fooBar);

    t1.join();
    t2.join();

    return 0;
}
