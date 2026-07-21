#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("diego",4);
        for (int i = 0;i < 19; i++)
        {
            a.incrementGrade();
        }
        std::cout << a << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat a("diego",-442);
        for (int i = 0;i < 19; i++)
        {
            a.incrementGrade();
        }
        std::cout << a << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat a("diego",149);
        for (int i = 0;i < 19; i++)
        {
            a.decrementGrade();
        }
        std::cout << a << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}