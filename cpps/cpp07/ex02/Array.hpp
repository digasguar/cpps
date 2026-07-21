#include <cstddef>
#include <string>
#include <iostream>

template <typename T>
class Array
{
private:
    T *_element;
    size_t _size;

public:
    Array() : _element(NULL), _size(0) {};

    Array(unsigned int n) : _element(new T[n]), _size(n) {}

    Array(const Array &other) : _element(new T[other._size]), _size(other._size)
    {
        for (size_t i = 0; i < other._size; i++)
        {
            _element[i] = other._element[i];
        }
    };

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _element;

            _size = other._size;
            _element = new T[_size];

            for (size_t i = 0; i < _size; i++)
                _element[i] = other._element[i];
        }
        return (*this);
    }

    ~Array()
    {
        delete[] _element;
    };

    const T &operator[](size_t index) const
    {
        if (index >= _size)
            throw std::out_of_range("index out of bounds");
        return (_element[index]);
    }

    T &operator[](size_t index)
    {
        if (index >= _size)
            throw std::out_of_range("index out of bounds");
        return (_element[index]);
    }

    size_t size() const
    {
        return (_size);
    }
};