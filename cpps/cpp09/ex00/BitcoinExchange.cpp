#include "BitcoinExchange.hpp"

const char *BitcoinExchange::errorFileExeption::what() const throw()
{
    return ("Error: could not open file.");
}

BitcoinExchange::BitcoinExchange(char *path)
{
    loadDB("data.csv", this->_data);
    processInput(path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    copy_map(other._data);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    copy_map(other._data);
    return (*this);
}

void BitcoinExchange::loadDB(std::string path, std::map<std::string, float> &target) const
{
    std::string content;
    std::ifstream fd(path.c_str());
    if (!fd)
    {
        throw(errorFileExeption());
    }
    while (std::getline(fd, content))
    {
        if (content == "date,exchange_rate")
            continue;
        std::stringstream ss(content);
        std::string date;
        std::string value;
        std::getline(ss, date, ',');
        std::getline(ss, value);
        float value_int = std::atof(value.c_str());
        target[date] = value_int;
    }
    fd.close();
}

void BitcoinExchange::copy_map(std::map<std::string, float> other)
{
    std::map<std::string, float>::iterator it;
    for (it = other.begin(); it != other.end(); ++it)
    {
        this->_data[it->first] = it->second;
    }
};

void BitcoinExchange::processInput(const std::string &file)
{
    std::ifstream fd(file.c_str());
    std::string line;

    if (!fd)
        throw errorFileExeption();
    std::getline(fd, line);
    while (std::getline(fd, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        if (!std::getline(ss, date, '|') || !std::getline(ss, value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        trim(date);
        if (!isValidDate(date))
        {
            std::cout << "Error: not a valid date." << std::endl;
            continue;
        }
        trim(value);
        if (!isValidValue(value))
        {
            std::cout << "Error: not a valid value." << std::endl;
            continue;
        }
        float val = std::atof(value.c_str());
        if (val < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        float rate = getRate(date);
        std::cout << date << " => " << val << " = " << val * rate << std::endl;
    }
}

void trim(std::string &s)
{
    s.erase(0, s.find_first_not_of(" \t"));
    s.erase(s.find_last_not_of(" \t") + 1);
}

float BitcoinExchange::getRate(const std::string &date)
{
    std::map<std::string, float>::iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return (it->second);
    if (it == _data.begin())
        return (it->second);
    if (it == _data.end() || it->first != date)
        --it;
    return (it->second);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year <= 0 || month < 1 || month > 12)
        return (false);
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (leap)
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return (false);
    return (true);
}

bool BitcoinExchange::isValidValue(std::string value)
{
    if (value.empty())
        return (false);
    bool decimalPoint = false;
    for (size_t i = 0; i < value.size(); ++i)
    {
        if (value[i] == '.')
        {
            if (decimalPoint)
                return (false);
            decimalPoint = true;
        }
        else if (!isdigit(value[i]))
        {
            return (false);
        }
    }
    return (true);
}
