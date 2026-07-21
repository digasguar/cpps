#ifndef FORM_H
# define FORM_H
#include <string>
#include <iostream>
class Bureaucrat;


class Form
{
private:
    const std::string _name;
    bool _sig;
    const int _grade_signed;
    const int _grade_execute;
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
    class FormAlredySignedExeption : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    ~Form();
    Form(const Form &other);
    Form(const std::string name, const int grade_sign, const int grade_exec);
    Form& operator=(const Form &other);
    const std::string& get_name();
    bool get_sig();
    int get_grade_sig();
    int get_grade_exec();
    void beSigned(Bureaucrat &other);
};
std::ostream& operator<<(std::ostream &out,Form& form);
#endif
