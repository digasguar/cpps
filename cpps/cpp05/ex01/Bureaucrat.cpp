#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exeption grade to Low");
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exeption grade to High");
}

Bureaucrat::Bureaucrat():_name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if(grade > 150)
    {
        throw GradeTooLowException();
    }
    if(grade < 1)
    {
        throw GradeTooHighException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucat copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

const std::string Bureaucrat::getName()
{
    return(this->_name);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw GradeTooHighException();
    this->_grade--;
}
void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw GradeTooLowException();
    this->_grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &Bureaucrat)
{
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return (out);
}

int Bureaucrat::getGrade()
{
    return(this->_grade);
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.get_name() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->_name << " couldn’t sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat(){}

