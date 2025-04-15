#include "Serializer.hpp"

// Takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t   Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

// Takes an unsigned integer parameter and converts it to a pointer to Data
Data*       Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
