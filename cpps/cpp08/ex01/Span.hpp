#ifndef SPAN_H
#define SPAN_H
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _data;

public:
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int N);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename T>
    void addRange(T begin, T end)
    {
        if (std::distance(begin, end) + _data.size() > _maxSize)
                throw std::runtime_error("Span is full");
        for (T it = begin; it != end; ++it)
        {
            _data.push_back(*it);
        }
    }
};

#endif