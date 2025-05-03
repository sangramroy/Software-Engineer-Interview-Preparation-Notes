/*
Problem 4: 1195. Fizz Buzz Multithreaded

We need to print numbers from 1 to n. But:
- Print "Fizz" for multiples of 3.
- Print "Buzz" for multiples of 5.
- Print "FizzBuzz" for multiples of both 3 and 5.
- Print number otherwise.

Each output must be printed by a dedicated thread.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int counter = 1;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void fizz() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return counter > n || (counter % 3 == 0 && counter % 5 != 0); });
            if (counter > n) break;
            cout << "Fizz ";
            ++counter;
            cv.notify_all();
        }
    }

    void buzz() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return counter > n || (counter % 5 == 0 && counter % 3 != 0); });
            if (counter > n) break;
            cout << "Buzz ";
            ++counter;
            cv.notify_all();
        }
    }

    void fizzbuzz() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return counter > n || (counter % 3 == 0 && counter % 5 == 0); });
            if (counter > n) break;
            cout << "FizzBuzz ";
            ++counter;
            cv.notify_all();
        }
    }

    void number() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return counter > n || (counter % 3 != 0 && counter % 5 != 0); });
            if (counter > n) break;
            cout << counter << " ";
            ++counter;
            cv.notify_all();
        }
    }
};

int main() {
    int n = 15;
    FizzBuzz fizzBuzz(n);

    thread t1(&FizzBuzz::fizz, &fizzBuzz);
    thread t2(&FizzBuzz::buzz, &fizzBuzz);
    thread t3(&FizzBuzz::fizzbuzz, &fizzBuzz);
    thread t4(&FizzBuzz::number, &fizzBuzz);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
