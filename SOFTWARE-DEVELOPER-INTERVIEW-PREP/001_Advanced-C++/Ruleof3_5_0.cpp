#include <iostream>
using namespace std;

class Test {
    int x;
    int* y;

public:
    // Default Constructor
    Test() {
        x = 0;
        y = new int(0);
        cout << "Inside default constructor\n";
    }

    // Parameterized Constructor
    Test(int a, int b) {
        x = a;
        y = new int(b);
        cout << "Inside parameterized constructor\n";
    }

    // Copy Constructor (Deep Copy)
    Test(const Test& obj) {
        x = obj.x;
        y = new int(*obj.y);
        cout << "Inside copy constructor\n";
    }

    // Move Constructor
    Test(Test&& obj) noexcept {
        x = obj.x;
        y = obj.y;
        obj.x = 0;
        obj.y = nullptr;
        cout << "Inside move constructor\n";
    }

    // Copy Assignment Operator (Deep Copy)
    Test& operator=(const Test& obj) {
        if (this != &obj) {
            x = obj.x;
            delete y;
            y = new int(*obj.y);
            cout << "Inside copy assignment operator\n";
        }
        return *this;
    }

    // Move Assignment Operator
    Test& operator=(Test&& obj) noexcept {
        if (this != &obj) {
            x = obj.x;
            delete y;
            y = obj.y;
            obj.x = 0;
            obj.y = nullptr;
            cout << "Inside move assignment operator\n";
        }
        return *this;
    }

    // Destructor
    ~Test() {
        delete y;
        cout << "Inside destructor\n";
    }

    void show() const {
        cout << "Value of x: " << x << endl;
        cout << "Value pointed by y: " << (y ? *y : 0) << endl;
        cout << "Address stored in y: " << y << "\n\n";
    }
};

int main() {
    Test t1;
    t1.show();

    Test t2(40, 50);
    t2.show();

    Test t3(t2);  // Copy constructor
    t3.show();

    Test t4 = move(t3);  // Move constructor
    t4.show();

    Test t5;
    t5 = t4;  // Copy assignment
    t5.show();

    Test t6;
    t6 = move(t4);  // Move assignment
    t6.show();

    return 0;
}
