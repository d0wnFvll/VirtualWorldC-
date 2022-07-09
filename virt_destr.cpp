#include <memory>
#include <iostream>

struct Base {
    virtual ~Base() { std::cout << "~Base()\n"; }
    
    virtual void f() = 0;
};

struct Derived : Base {
    ~Derived() { std::cout << "~Derived()\n"; }
    
    void f() override {
        std::cout << "This is Derived\n\n";
    }
};

void f(std::unique_ptr<Base> const &ptr) {
    ptr->f();
}

int main() {
    std::unique_ptr<Base> b = std::unique_ptr<Derived>(new Derived);
    f(b);
    
    return 0;
}
