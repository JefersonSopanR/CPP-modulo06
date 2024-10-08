#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) 
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) 
{
    (void)obj;
    return *this;
}

void ScalarConverter::convert(const std::string &input) 
{
    ScalarConverter instance; // Create an instance to call non-static methods
    double value = 0;
    char *end = NULL;

    if (instance.isChar(input))
        value = static_cast<double>(input[0]);
    else if (instance.isInt(input))
        value = static_cast<double>(std::strtol(input.c_str(), &end, 10));
    else if (instance.isFloat(input))
        value = static_cast<double>(std::strtof(input.c_str(), &end));
    else if (instance.isDouble(input))
        value = std::strtod(input.c_str(), &end);
    else if (instance.isLiteral(input)) 
    {
        if (input == "nan" || input == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (input == "+inf" || input == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (input == "-inf" || input == "-inff")
            value = -std::numeric_limits<double>::infinity();
    } 
    else 
    {
        std::cerr << "Invalid input!" << std::endl;
        return;
    }

    instance.printChar(value);
    instance.printInt(value);
    instance.printFloat(value);
    instance.printDouble(value);
}


bool ScalarConverter::isChar(const std::string &input) 
{
    return input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]);
}

bool ScalarConverter::isInt(const std::string &input) 
{
    char *end;
    long value = std::strtol(input.c_str(), &end, 10);
    return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string &input) 
{
    char *end;
    std::strtof(input.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string &input) 
{
    char *end;
    std::strtod(input.c_str(), &end);
    return *end == '\0';
}

bool ScalarConverter::isLiteral(const std::string &input) 
{
    return input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff";
}

void ScalarConverter::printChar(double value) 
{
    if (isnan(value) || isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) 
{
    if (isnan(value) || isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) 
{
    if (isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (isinf(value)) 
    {
        if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    } 
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) 
{
    if (isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (isinf(value)) 
    {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    } 
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
