#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <string>
#include <iostream>

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
    const std::string getName();
    int getGrade();
    void incrementGrade();
    void  decrementGrade();
};
std::ostream &operator<<(std::ostream &out, Bureaucrat &other);
#endif