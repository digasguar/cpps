#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}

template <typename T>
void increment(T &x)
{
    x++;
}

template <typename T, typename F>
void iter(T *array, const size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T, typename F>
void iter(const T *array, const size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif