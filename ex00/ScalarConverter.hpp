#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>   // For std::strtol, std::strtof, std::strtod
#include <iomanip>   // For std::setprecision
#include <cmath>     // For isnan, isinf
#include <cctype>    // For isprint
#include <cmath>     // For isnan, isinf
#include <cctype>    // For isprint

class ScalarConverter 
{ 
    public:
        // Static method to handle conversion
        static void convert(const std::string &input);

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);

        bool isChar(const std::string &input);
        bool isInt(const std::string &input);
        bool isFloat(const std::string &input);
        bool isDouble(const std::string &input);
        bool isLiteral(const std::string &input);
    
        void printChar(double value);
        void printInt(double value);
        void printFloat(double value);
        void printDouble(double value);
};

#endif
