#include <iostream>

struct Base {
    virtual void f() {
        std::cout << "Base\n";
    }
};

struct Right : virtual Base {
};

struct Left : virtual Base {
};

struct Derived : Right, Left {
};

int main() {
    Derived d;
    d.f();
    
    return 0;
}
