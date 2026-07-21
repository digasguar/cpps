#ifndef BITOIN_HPP
#define BITOIN_HPP
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <math.h>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;

public:
    class errorFileExeption : public std::exception
    {
        virtual const char *what() const throw();
    };
    BitcoinExchange(char *path);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void loadDB(std::string path, std::map<std::string, float> &target) const;
    void copy_map(std::map<std::string, float> other);
    ~BitcoinExchange();
    void processInput(const std::string &file);
    float getRate(const std::string &date);
    bool isValidDate(const std::string &date);
    bool isValidValue(std::string value);
};
void trim(std::string &s);
#endif