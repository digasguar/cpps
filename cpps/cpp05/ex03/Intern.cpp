#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern &other)
{
    (void) other;
    return (*this);
}

AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm* (*functions[3])(std::string) = {createShrubbery, createRobotomy, createPresidential};
    std::string names [3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl; 
            return(functions[i](target));
        }
    }
    throw (Intern::FormNotExist());
}

const char * Intern::FormNotExist::what() const throw()
{
    return ("this form cannot be created");
}