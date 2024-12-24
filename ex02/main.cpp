#include "Base.hpp"
#include <iostream>

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Test #" << i + 1 << ":" << std::endl;
        
        Base* ptr = generate();
        
        std::cout << "Pointer identification: ";
        identify(ptr);
        
        std::cout << "Reference identification: ";
        identify(*ptr);
        
        std::cout << std::endl;
        
        delete ptr;
    }
    
    return 0;
}