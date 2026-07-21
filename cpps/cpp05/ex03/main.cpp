#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        Bureaucrat b1("b1",11);
        ShrubberyCreationForm s1("prueba");
        s1.beSigned(b1);
        std::cout << s1 << std::endl;
        b1.executeForm(s1);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    try
    {
        Bureaucrat b2("b1",3);
        PresidentialPardonForm s2("prueba");
        s2.beSigned(b2);
        std::cout << s2 << std::endl;
        b2.executeForm(s2);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("b1",3);
        PresidentialPardonForm s2("prueba");
        s2.beSigned(b2);
        std::cout << s2 << std::endl;
        b2.executeForm(s2);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}