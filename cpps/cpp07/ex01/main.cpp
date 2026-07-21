#include "iter.hpp"

int main()
{
    char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const int carr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    iter(arr, 9, print<char>);
    std::cout << std::endl;
    iter(arr, 8, increment<char>);
    std::cout << "-------------------------------------" << std::endl;
    iter(arr, 8, print<int>);
    std::cout << std::endl;
    std::cout << "__________________________________________" << std::endl;
    iter(carr, 8, print<int>);
    std::cout << std::endl;
    return 0;
}