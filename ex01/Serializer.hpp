#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
    int member;
    std::string title;
    std::string description;
};

class   Serializer {
    public:
        static uintptr_t   serialize( Data* ptr );
        static Data*       deserialize( uintptr_t raw );

    private:
        Serializer();
        Serializer( const Serializer& copy );
        Serializer&  operator=( const Serializer& copy );
        ~Serializer();
};

#endif
