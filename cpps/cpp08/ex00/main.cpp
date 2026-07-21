#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    try
    {
    std::vector<int> v;

    v.push_back('a');
    v.push_back(20);
    v.push_back(30);

    std::vector<int>::iterator it = ::easyfind(v, 97);
    std::cout << *it << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
}