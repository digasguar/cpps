#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137),_target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return ("The File could not be created");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->_sig)
    {
        throw AForm::FormNotSigned();
    }
    if (executor.getGrade() > this->_grade_execute)
    {
        throw AForm::GradeTooLowException();
    }
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file)
        throw ShrubberyCreationForm::FileOpenException();
    file << "       _-_                _-_\n";
    file << "    /~~   ~~           /~~   ~~\\\n";
    file << " /~~         ~~     /~~         ~~\\ \n";
    file << "{               }  {               }\n";
    file << " \\  _-     -_  /    \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~        ~  \\\\ //  ~\n";
    file << "_- -   | | _- _   _-  -   | | _- _\n";
    file << "  _ -  | |   -_     _  -  | |   -_\n";
    file << "      // \\\\              // \\\\\n";
    file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other),_target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}
