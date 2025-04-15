#include "ScalarConverter.hpp"

const char *ScalarConverter::ConversionException::what() const throw() {
    return ("Cannot convert to the implied type.");
}

ScalarConverter::Type  getType(const std::string& ref) {
    // Check if the length of the string is 1 
    // AND it is not a number because all printable chars 
    // EXCEPT numbers are chars
    if (ref.length() == 1 && (ref[0] < '0' || ref[0] > '9')) {
        // Return the char type
        return (ScalarConverter::E_CHAR);
    }
    // Check if the string ends with an 'f'
    else if (ref[ref.length() - 1] == 'f') {
        // Return the float type
        return (ScalarConverter::E_FLOAT);
    }
    // Check if the string contains a decimal point
    else if (ref.find('.') != std::string::npos) {
        // Return the double type
        return (ScalarConverter::E_DOUBLE);
    }
    // Return the int type by default
    return (ScalarConverter::E_INT);
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
    int     precision = 1;
    size_t  decimal_index = ref.find_first_of('.');
    if (decimal_index != std::string::npos) {
        precision = ref.length() - (decimal_index + 1);
    }
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << val_type << value << std::endl;
}

void    displayDecimal(
    const std::string& val_type,
    const std::string& ref,
    float value
) {
    int     precision = 1;
    size_t  decimal_index = ref.find_first_of('.');
    if (decimal_index != std::string::npos) {
        precision = ref.length() - (decimal_index + 1);
    }
    std::cout << std::fixed << std::setprecision(precision);
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
    std::string refDup = ref.substr(0, ref.length() - 1);
    std::istringstream ss(refDup);
    float   converted;
    char    c;

    ss >> converted;
    if (ss.fail() || ss.get(c)) {
        throw ScalarConverter::ConversionException();
    }

    displayValue("char: ", static_cast<char>(converted));
    displayValue("int: ", static_cast<int>(converted));
    displayDecimal("float: ", refDup, converted);
    displayDecimal("double: ", refDup, static_cast<double>(converted));
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
