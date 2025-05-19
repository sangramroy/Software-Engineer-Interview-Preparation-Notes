#include <iostream>
#include <future>
using namespace std;

void func(promise<int>&& p, int x) {
    p.set_value(x * x);
}

int func2(int x) {
    return 2 * x;
}

int main() {
    // Using promise & future
    promise<int> p;
    future<int> f = p.get_future();

    // Run func in a separate thread with moved promise
    thread t1(func, move(p), 10);

    // Using async for func2
    future<int> f2 = async(launch::async, func2, 10);

    cout << "Value from func (10*10): " << f.get() << endl;
    cout << "Value from func2 (2*10): " << f2.get() << endl;

    t1.join(); // Always join threads
    return 0;
}
