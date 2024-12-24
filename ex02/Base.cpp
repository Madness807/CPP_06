#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base* generate(void) {
    static bool first = true;
    if (first) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        first = false;
    }
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast const &) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast const &) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::bad_cast const &) {}
}