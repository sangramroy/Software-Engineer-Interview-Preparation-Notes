#include <iostream>
#include <string>
using namespace std;

// Step 1: Base Pizza class
class Pizza {
public:
    virtual void prepare() = 0;  // pure virtual function
    virtual ~Pizza() {}
};

// Step 2: Derived pizza types
class Margherita : public Pizza {
public:
    void prepare() override {
        cout << "Preparing Margherita Pizza" << endl;
    }
};

class Farmhouse : public Pizza {
public:
    void prepare() override {
        cout << "Preparing Farmhouse Pizza" << endl;
    }
};

class PeppyPaneer : public Pizza {
public:
    void prepare() override {
        cout << "Preparing Peppy Paneer Pizza" << endl;
    }
};

// Step 3: Pizza Factory
class PizzaFactory {
public:
    static Pizza* createPizza(const string& type) {
        if (type == "Margherita") return new Margherita();
        else if (type == "Farmhouse") return new Farmhouse();
        else if (type == "PeppyPaneer") return new PeppyPaneer();
        else return nullptr;
    }
};

// Step 4: Client code
int main() {
    Pizza* pizza = PizzaFactory::createPizza("PeppyPaneer");

    if (pizza) {
        pizza->prepare();
        delete pizza;
    } else {
        cout << "Invalid pizza type!" << endl;
    }

    return 0;
}
