#ifndef FORM_H
# define FORM_H
#include <string>
#include <iostream>
class Bureaucrat;


class AForm
{
protected:
    const std::string _name;
    bool _sig;
    const int _grade_signed;
    const int _grade_execute;
public:
    class FormNotSigned : public std::exception
    {
        virtual const char* what() const throw();
    }; 
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
    class FormAlredySignedExeption : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    virtual ~AForm();
    AForm(const AForm &other);
    AForm(const std::string name, const int grade_sign, const int grade_exec);
    AForm& operator=(const AForm &other);
    const std::string& get_name() const;
    bool get_sig();
    int get_grade_sig() const;
    int get_grade_exec() const;
    void beSigned(Bureaucrat &other);
    virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream &out,AForm& Aform);
#endif
