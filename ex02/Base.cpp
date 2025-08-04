#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base::~Base() {};

// Randomly instantiates A, B, or C and returns the instance as a Base pointer
Base*   generate(void) {
    Base*   random;

    int randomVal = rand() % 3 + 1;
    if (randomVal == 1)
        random = new A;
    else if (randomVal == 2)
        random = new B;
    else 
        random = new C;

    return (random);
};

// Prints the actual type of the object pointed to by p: 'A', 'B', or 'C'
void    identify(Base* p) {
    Base*  castPtr = dynamic_cast<A*>(p);
    if (castPtr) {
        std::cout << "A" << std::endl;
        return ;
    }
    castPtr = dynamic_cast<B*>(p);
    if (castPtr) {
        std::cout << "B" << std::endl;
        return ;
    }
    castPtr = dynamic_cast<C*>(p);
    if (castPtr) {
        std::cout << "C" << std::endl;
        return ;
    }
    std::cout << "Unknown" << std::endl;
};

// Prints the actual type of the object referenced by p: 'A', 'B', or 'C'
void    identify(Base& p) {
    try {
        __attribute_maybe_unused__
        A&   a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception &e) { }
    try {
        __attribute_maybe_unused__
        B&   b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::exception &e) { }
    try {
        __attribute_maybe_unused__
        C&   c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception &e) { }
};
