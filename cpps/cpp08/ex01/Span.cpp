#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data){}

Span &Span::operator=(const Span &other)
{
    if (&other != this)
    {
        this->_maxSize = other._maxSize;
        this->_data = other._data;
    }
    return (*this);
}

void Span::addNumber(int N)
{
    if (this->_data.size() < this->_maxSize)
        this->_data.push_back(N);
    else
        throw(std::runtime_error("container busy"));
}

int Span::shortestSpan() const
{
    if (this->_data.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> tmp = this->_data;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; ++i)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }
    return (shortest);
}

int Span::longestSpan() const
{
    if (this->_data.size() < 2)
        throw(std::runtime_error("Not enough numbers"));
    int max = *std::max_element(this->_data.begin(), this->_data.end());
    int min = *std::min_element(this->_data.begin(), this->_data.end());
    return (max - min);
}

