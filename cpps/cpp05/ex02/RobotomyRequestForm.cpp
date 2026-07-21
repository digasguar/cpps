#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),_target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("RobotomyRequestForm", 72, 45) ,_target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

const char* RobotomyRequestForm::FailedRobotomized::what() const throw()
{
    return ("the robotomy failed");
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->_sig)
    {
        throw AForm::FormNotSigned();
    }
    if (executor.getGrade() > this->_grade_execute)
    {
        throw AForm::GradeTooLowException();
    }
    int i = (rand()%2)+1;
    std::cout << "bbrbrbrbr" << std::endl;
    if (i % 2 == 1)
    {
        throw RobotomyRequestForm::FailedRobotomized();
    }
    std::cout << this->_target << " has been robotomized" << std::endl;
}