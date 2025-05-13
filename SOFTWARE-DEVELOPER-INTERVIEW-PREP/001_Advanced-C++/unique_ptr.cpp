/*

Smart pointers are wrapper classes around raw pointers that automatically manage memory.

They help:

Avoid memory leaks (no need to call delete).

Make your code safer and easier to read.

Reduce bugs from dangling pointers.

👇 Three Main Types of Smart Pointers in C++
Smart Pointer	  Ownership	                          Can be copied?	             Use Case
unique_ptr	     Sole ownership	                           ❌ No	One owner,             no sharing
shared_ptr	     Shared ownership (reference count)      	✅ Yes	                   Multiple owners share a resource
weak_ptr	     Non-owning reference to shared_ptr

#include <iostream>
#include <memory> // for smart pointers

using namespace std;

int main() {
    unique_ptr<int> ptr = make_unique<int>(10);  // Create a unique_ptr holding int(10)
    cout << "Value: " << *ptr << endl;           // Access the value

    // unique_ptr automatically deletes the memory when it goes out of scope
    return 0;
}


*/
#include <iostream>
using namespace std;

template<typename T>
class MyUniquePtr {
private:
    T* ptr;

public:
    // Default constructor
    MyUniquePtr() {
        ptr = NULL;  // Use NULL instead of nullptr
    }

    // Constructor with raw pointer
    MyUniquePtr(T* p) {
        ptr = p;
    }

    // Destructor
    ~MyUniquePtr() {
        delete ptr;
    }

    // Delete copy constructor and copy assignment
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // Move constructor
    MyUniquePtr(MyUniquePtr&& other) {
        ptr = other.ptr;
        other.ptr = NULL;
    }

    // Move assignment
    MyUniquePtr& operator=(MyUniquePtr&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = NULL;
        }
        return *this;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const {
        return ptr;
    }

    // Get raw pointer
    T* get() const {
        return ptr;
    }
};

int main() {
    cout << "=== MyUniquePtr Test ===" << endl;

    MyUniquePtr<int> uptr(new int(42));
    cout << "Value in unique pointer: " << *uptr << endl;

    MyUniquePtr<int> moved;
    moved = std::move(uptr);
    cout << "Value in moved unique pointer: " << *moved << endl;

    if (uptr.get() == NULL) {
        cout << "Original pointer is now NULL" << endl;
    }

    return 0;
}
