#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &str)
{
    return (str.length() == 1 && !isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str)
{
    size_t i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool ScalarConverter::isFloat(const std::string &str)
{
    bool find = false;
    size_t i = 0;

    if (str.find('.') == std::string::npos || str[str.length() - 1] != 'f')
    {
        return (false);
    }
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (find)
                return (false);
            else
                find = true;
        }
        if (!isdigit(str[i]) && (str[i] != '.' && str[i] != 'f'))
        {
            return (false);
        }
    }
    return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
    bool find = false;
    size_t i = 0;

    if (str.find('.') == std::string::npos)
    {
        return (false);
    }
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (find)
                return (false);
            else
                find = true;
        }
        if (!isdigit(str[i]) && str[i] != '.')
        {
            return (false);
        }
    }
    return (true);
}

bool ScalarConverter::isPseudo_literals(const std::string &str)
{
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

void ScalarConverter::printPseudo(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (isPseudo_literals(str))
    {
        printPseudo(str);
        return;
    }
    if (isChar(str))
    {
        printChar(str);
    }
    else if (isInt(str))
    {
        printInt(str);
    }
    else if (isFloat(str))
    {
        printFloat(str);
    }
    else if (isDouble(str))
    {
        printDouble(str);
    }
    else
    {
        std::cout << "Error: invalid input" << std::endl;
    }
}

void printChar(const std::string &str)
{
    char c = str[1];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    if (!isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char :'" << c << "'\n";
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double :" << d << ".0" << std::endl;
}

void printInt(const std::string &str)
{
    long l = std::strtol(str.c_str(), NULL, 10);

    if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    int i = static_cast<int>(l);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    if (i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else if (!isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void printFloat(const std::string &str)
{
    float f = std::strtof(str.c_str(), NULL);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    if (f < 0 || f > 127)
        std::cout << "char: impossible\n";
    else if (!isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f;
    if (f == i)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << d;
    if (d == i)
        std::cout << ".0";
    std::cout << std::endl;
}

void printDouble(const std::string &str)
{
    double d = std::strtod(str.c_str(), NULL);

    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!isprint(c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
    std::cout << "int: ";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << i << std::endl;
    std::cout << "float: " << f;
    if (f == i)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << d;
    if (d == i)
        std::cout << ".0";
    std::cout << std::endl;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}
