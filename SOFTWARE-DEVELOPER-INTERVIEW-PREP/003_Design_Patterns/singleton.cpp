/*
================================================================================
🧠 SINGLETON DESIGN PATTERN IN C++ (Thread-Safe with Lazy Initialization)
================================================================================

📌 PURPOSE:
- The Singleton pattern ensures a class has only ONE instance 
  and provides a global access point to it.

📌 KEY CHARACTERISTICS:
- Single instance across the program
- Lazy initialization: Instance is created when first accessed
- Thread-safe: Uses `std::mutex` and `unique_lock` to avoid data races
- Copy and assignment operations are DELETED to prevent duplication

📌 ADVANTAGES:
- Controlled access to sole instance
- Useful for logging, configuration, resource management

📌 THIS IMPLEMENTATION:
- Uses raw pointer for instance
- Thread-safe with `std::mutex`
- Deletes copy constructor and assignment operator

📌 RULES FOLLOWED:
- C++11 `unique_lock` for better lock management
- Deleted copy operations to prevent accidental copies

================================================================================
*/

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Singleton {
    int data;  // Example data member

    static Singleton* instance;  // Static pointer to singleton instance
    static mutex mtx;            // Mutex for thread-safety

    // Private constructor to prevent external instantiation
    Singleton() = default;

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public static access method
    static Singleton* getInstance() {
        unique_lock<mutex> lock(mtx);  // Thread-safe lock
        if (instance == nullptr) {
            instance = new Singleton();
            cout << "[Singleton] Fresh instance created\n";
        }
        return instance;
    }

    void setData(int val, const string& caller) {
        data = val;
        cout << "[" << caller << "] set data to: " << val << endl;
    }

    void getData(const string& caller) {
        cout << "[" << caller << "] accessed data: " << data << endl;
    }
};

// Static member definitions
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    cout << "=== Singleton Design Pattern Demo ===\n\n";

    Singleton* ptr1 = Singleton::getInstance();
    ptr1->setData(90, "ptr1");
    ptr1->getData("ptr1");

    Singleton* ptr2 = Singleton::getInstance();
    ptr2->getData("ptr2");

    return 0;
}
