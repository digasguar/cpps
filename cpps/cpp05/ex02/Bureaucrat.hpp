#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <string>
#include <iostream>
#include "AForm.hpp"
#include <fstream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void  decrementGrade();
    void  signForm(AForm &Form);
    void executeForm(AForm const & form) const;
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);
#endif