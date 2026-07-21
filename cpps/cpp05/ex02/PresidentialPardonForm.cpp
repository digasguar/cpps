#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm("PresidentialPardonForm",25,5),_target(other._target){}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->_sig)
    {
        throw AForm::FormNotSigned();
    }
    if (executor.getGrade() > this->_grade_execute)
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << this->_target <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
}