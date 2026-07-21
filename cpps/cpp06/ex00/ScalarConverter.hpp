#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>


class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter &other);
public:
    ~ScalarConverter();
    static void convert(const std::string &str);
    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);
    static bool isPseudo_literals(const std::string &str);
    static void printPseudo(const std::string &str);
};
void printDouble(const std::string &str);
void printFloat(const std::string &str);
void printInt(const std::string &str);
void printChar(const std::string &str);