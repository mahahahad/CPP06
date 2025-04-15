#include "ScalarConverter.hpp"

const char *ScalarConverter::ConversionException::what() const throw() {
    return ("Cannot convert to the implied type.");
}

ScalarConverter::Type  getType(const std::string& ref) {
    //TODO: Get the type of the reference string
    (void) ref;
    return (ScalarConverter::E_CHAR);
}

void    displayValue(const std::string& val_type, char value) {
    std::cout << val_type;
    if (std::isprint(value))
        std::cout << value;
    else
        std::cout << "Not displayable";
    std::cout << std::endl;
}

void    displayValue(const std::string& val_type, int value) {
    std::cout << val_type << value << std::endl;
}

void    displayDecimal(
    const std::string& val_type,
    const std::string& ref,
    double value
) {
    size_t decimal_index = ref.find_first_of('.') + 1;
    int precision = ref.length() - decimal_index;
    std::cout << std::fixed
        << std::setprecision((decimal_index ? precision : 1));

    std::cout << val_type << value << std::endl;
}

void    displayDecimal(
    const std::string& val_type,
    const std::string& ref,
    float value
) {
    size_t decimal_index = ref.find_first_of('.') + 1;
    int precision = ref.length() - decimal_index;
    std::cout << std::fixed
        << std::setprecision((decimal_index ? precision : 1));

    std::cout << val_type << value << "f" << std::endl;
}

void    handleDouble(const std::string& ref) {
    std::istringstream ss(ref);
    double  converted;
    char    c;

    ss >> converted;
    if (ss.fail() || ss.get(c)) {
        throw ScalarConverter::ConversionException();
    }

    displayValue("char: ", static_cast<char>(converted));
    displayValue("int: ", static_cast<int>(converted));
    displayDecimal("float: ", ref, static_cast<float>(converted));
    displayDecimal("double: ", ref, converted);
}

void    handleFloat(const std::string& ref) {
    std::istringstream ss(ref);
    float   converted;
    char    c;

    ss >> converted;
    if (ss.fail() || ss.get(c)) {
        throw ScalarConverter::ConversionException();
    }

    displayValue("char: ", static_cast<char>(converted));
    displayValue("int: ", static_cast<int>(converted));
    displayDecimal("float: ", ref, converted);
    displayDecimal("double: ", ref, static_cast<double>(converted));
}

void    handleInt(const std::string& ref) {
    std::istringstream ss(ref);
    int     converted;
    char    c;

    ss >> converted;
    if (ss.fail() || ss.get(c)) {
        throw ScalarConverter::ConversionException();
    }

    displayValue("char: ", static_cast<char>(converted));
    displayValue("int: ", converted);
    displayDecimal("float: ", ref, static_cast<float>(converted));
    displayDecimal("double: ", ref, static_cast<double>(converted));
}

void    handleChar(const std::string& ref) {
    std::istringstream ss(ref);
    char    converted;
    char    c;

    ss >> converted;
    if (ss.fail() || ss.get(c)) {
        throw ScalarConverter::ConversionException();
    }

    displayValue("char: ", converted);
    displayValue("int: ", static_cast<int>(converted));
    displayDecimal("float: ", ref, static_cast<float>(converted));
    displayDecimal("double: ", ref, static_cast<double>(converted));
}

int ScalarConverter::convert(const std::string& ref) {
    switch(getType(ref)) {
        case (ScalarConverter::E_DOUBLE):
            handleDouble(ref);
            break ;
        case (ScalarConverter::E_FLOAT):
            handleFloat(ref);
            break ;
        case (ScalarConverter::E_INT):
            handleInt(ref);
            break ;
        case (ScalarConverter::E_CHAR):
            handleChar(ref);
            break;
    }
    return (0);
}
