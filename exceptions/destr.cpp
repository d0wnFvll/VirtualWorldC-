#include <memory>
#include <iostream>
#include <stdexcept>

struct Base {
    Base() {
        std::cout << "Base()\n";
    }

    ~Base() noexcept(false) { 
        std::cout << "~Base()\n";
        
        throw std::runtime_error("Destructor"); // std::terminate
    }
};

struct Derived : Base {
   Derived() {
       std::cout << "Derived()\n";
   } 
   
   ~Derived() {
       std::cout << "~Derived()\n";
   }
};

int main() {
    try {
        std::unique_ptr<Base> uptr = std::make_unique<Derived>();
    } catch (std::runtime_error &e) {
        std::cout << '\n' << e.what() << '\n';
    }
    
    return 0;
}
