#include "ScalarConverter.hpp"

const char *ScalarConverter::ConversionException::what() const throw() {
    return ("Cannot convert to the implied type.");
}

ScalarConverter::Type  getType(const std::string& ref) {
    // Get the type of the reference string
    (void) ref;
    return (ScalarConverter::E_INT);
}

int ScalarConverter::convert(const std::string& ref) {
    switch (getType(ref)) {
        case (ScalarConverter::E_INT):
        {
            std::istringstream ss(ref);
            int converted;
            char c;

            ss >> converted;
            if (ss.fail() || ss.get(c)) {
                throw ConversionException();
            }
            std::cout << "char: " ;
            if (std::isprint(converted)) {
                std::cout << static_cast<char>((unsigned char) converted);
            } else {
                std::cout << "Non displayable";
            }
            std::cout << std::endl;
            std::cout << "int: " << converted << std::endl;
            std::cout << "float: " << static_cast<float>(converted) << 
                "f" << std::endl;
            std::cout << "double: " << static_cast<double>(converted) << 
                std::endl;
            break;
        }
        case (ScalarConverter::E_DOUBLE):
        {
            break;
        }
        case (ScalarConverter::E_FLOAT):
        {
            break;
        }
        default:
        {
            break;
        }
    }
    return (0);
}
