/*
Problem 1: 1114. Print in Order

We need to print "first", "second", "third" in that order, using three threads.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int step = 0;

public:
    Foo() {}

    void first() {
        unique_lock<mutex> lock(mtx);
        cout << "first ";
        step = 1;
        cv.notify_all();
    }

    void second() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return step == 1; });
        cout << "second ";
        step = 2;
        cv.notify_all();
    }

    void third() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return step == 2; });
        cout << "third";
    }
};

int main() {
    Foo foo;

    thread t1(&Foo::first, &foo);
    thread t2(&Foo::second, &foo);
    thread t3(&Foo::third, &foo);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
