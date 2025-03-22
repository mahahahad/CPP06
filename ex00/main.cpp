#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR: Bad arguments\n";
        return (1);
    }
    try {
        ScalarConverter::convert(argv[1]);
    } catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}
