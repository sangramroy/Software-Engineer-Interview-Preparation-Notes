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
#include <memory>  // for shared_ptr

using namespace std;

int main() {
    shared_ptr<int> ptr1 = make_shared<int>(100);  // creates int on heap with value 100
    shared_ptr<int> ptr2 = ptr1;                   // both point to same memory

    cout << "Value from ptr1: " << *ptr1 << endl;
    cout << "Value from ptr2: " << *ptr2 << endl;
    cout << "Reference count: " << ptr1.use_count() << endl;

    return 0;
}


*/
#include <iostream>
using namespace std;

template<typename T>
class MySharedPtr {
private:
    T* ptr;           // raw pointer to the object
    int* refCount;    // pointer to the reference count

public:
    // Default constructor
    MySharedPtr() {
        ptr = NULL;
        refCount = NULL;
    }

    // Constructor with raw pointer
    MySharedPtr(T* p) {
        ptr = p;
        refCount = new int(1);  // start with 1 reference
    }

    // Copy constructor
    MySharedPtr(const MySharedPtr& other) {
        ptr = other.ptr;
        refCount = other.refCount;
        if (refCount != NULL) {
            (*refCount)++;
        }
    }

    // Copy assignment operator
    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            // Decrease current object's reference
            if (refCount != NULL) {
                (*refCount)--;
                if (*refCount == 0) {
                    delete ptr;
                    delete refCount;
                }
            }

            // Copy from other
            ptr = other.ptr;
            refCount = other.refCount;
            if (refCount != NULL) {
                (*refCount)++;
            }
        }
        return *this;
    }

    // Move constructor
    MySharedPtr(MySharedPtr&& other) {
        ptr = other.ptr;
        refCount = other.refCount;
        other.ptr = NULL;
        other.refCount = NULL;
    }

    // Move assignment operator
    MySharedPtr& operator=(MySharedPtr&& other) {
        if (this != &other) {
            // Clean up current
            if (refCount != NULL) {
                (*refCount)--;
                if (*refCount == 0) {
                    delete ptr;
                    delete refCount;
                }
            }

            // Take ownership from other
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = NULL;
            other.refCount = NULL;
        }
        return *this;
    }

    // Destructor
    ~MySharedPtr() {
        if (refCount != NULL) {
            (*refCount)--;
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
            }
        }
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const {
        return ptr;
    }

    // Get current reference count
    int use_count() const {
        if (refCount == NULL) return 0;
        return *refCount;
    }

    // Get raw pointer
    T* get() const {
        return ptr;
    }
};

int main() {
    cout << "=== MySharedPtr Test ===" << endl;

    MySharedPtr<int> sp1(new int(100));
    cout << "sp1 value: " << *sp1 << " | count: " << sp1.use_count() << endl;

    MySharedPtr<int> sp2 = sp1;
    cout << "sp2 copied from sp1 | count: " << sp2.use_count() << endl;

    {
        MySharedPtr<int> sp3 = sp2;
        cout << "sp3 copied from sp2 | count: " << sp3.use_count() << endl;
    } // sp3 goes out of scope here

    cout << "After sp3 destroyed | count: " << sp1.use_count() << endl;

    return 0;
}
