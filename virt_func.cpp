#include <iostream>

struct Base {
    virtual void f() {
        std::cout << "Base\n";
    };
};

struct Derived : Base {
    void f() override {
        std::cout << "Derived\n";
    }
};

int main() {
    Base b;
    Derived d;
    
    d.f(); // Output: Derived
    b.f(); // Output: Base
    
    Base *bp = &d; // Standard conversion
    bp->f(); // Output: Derived
    
    return 0;
}
