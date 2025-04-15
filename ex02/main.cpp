#include "Base.hpp"

int main(void) {
    Base    *test = generate();
    std::cout << "Type of base generated: ";
    identify(test);
    delete test;

    Base    *test2 = generate();
    Base    &test2Ref = *test2;
    std::cout << "Type of base generated: ";
    identify(test2Ref);
    delete test2;

    return (0);
}
