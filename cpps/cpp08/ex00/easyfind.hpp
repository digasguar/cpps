#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>


template <typename T>
typename T::iterator easyfind (T& container, int value)
{
    typename T::iterator result = std::find(container.begin(), container.end(), value);
    if (result == container.end())
        throw std::runtime_error ("value not find");
    return (result);
}
#endif