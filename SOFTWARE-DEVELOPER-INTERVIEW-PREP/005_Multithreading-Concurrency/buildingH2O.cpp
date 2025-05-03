/*
Problem: Building H2O

We need to print "H2O" alternately using two threads, one printing "H" and the other printing "2" and "O" in the correct sequence.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class H2O {
private:
    mutex mtx;
    condition_variable cv;
    int hydrogen_count = 0;
    int oxygen_count = 0;

public:
    H2O() {}

    void hydrogen(function<void()> printHydrogen) {
        for (int i = 0; i < 2; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return hydrogen_count < 2 && oxygen_count == 0; });
            printHydrogen();
            hydrogen_count++;
            if (hydrogen_count == 2) {
                oxygen_count = 1;
                cv.notify_all();
            }
        }
    }

    void oxygen(function<void()> printOxygen) {
        for (int i = 0; i < 1; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return oxygen_count == 1; });
            printOxygen();
            hydrogen_count = 0;  // Reset hydrogen count after oxygen
            oxygen_count = 0;
            cv.notify_all();
        }
    }
};

void printHydrogen() {
    cout << "H";
}

void printOxygen() {
    cout << "O";
}

int main() {
    H2O h2o;

    thread t1(&H2O::hydrogen, &h2o, printHydrogen);
    thread t2(&H2O::hydrogen, &h2o, printHydrogen);
    thread t3(&H2O::oxygen, &h2o, printOxygen);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
