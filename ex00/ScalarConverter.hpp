#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

class   ScalarConverter {
    public:
        static int  convert( const std::string& ref );
        enum    Type { E_INT, E_DOUBLE, E_FLOAT, E_CHAR };
    
    public:
        class   ConversionException: public std::exception {
            public:
                virtual const char * what() const throw();
        };

    private:
        ScalarConverter( void );
        ScalarConverter( const ScalarConverter& copy );
        ScalarConverter&  operator=( const ScalarConverter& copy );
        ~ScalarConverter( void );
};

#endif
