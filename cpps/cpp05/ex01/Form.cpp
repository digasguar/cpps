#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int grade_sign, const int grade_exec):_name(name),_sig(false), _grade_signed(grade_sign), _grade_execute(grade_exec)
{
    if (this->_grade_signed > 150 || this->_grade_execute > 150)
        throw Form::GradeTooLowException();
    if (this->_grade_signed < 1 || this->_grade_execute < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &other):_name(other._name), _sig(other._sig), _grade_signed(other._grade_signed), _grade_execute(other._grade_execute)
{
    std::cout << "Bureaucat copy constructor" << std::endl;
}

const std::string& Form::get_name()
{
    return (this->_name);
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_sig = other._sig;
    }
    return (*this);
}

bool Form::get_sig()
{
    return (this->_sig);
}

int Form::get_grade_sig()
{
    return (this->_grade_signed);
}

int Form::get_grade_exec()
{
    return (this->_grade_execute);
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Exeption grade to Low");
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Exeption grade to High");
}

const char* Form::FormAlredySignedExeption::what() const throw()
{
    return ("Exeption Form Alredy signed");
}

std::ostream& operator<<(std::ostream &out, Form &form)
{
    std::string sig;
    if (form.get_sig())
        sig = "True";
    else
        sig = "False";
    out << form.get_name() << " " << sig << " " << form.get_grade_sig() << " " << form.get_grade_exec();
    return (out);
}

void Form::beSigned(Bureaucrat &other)
{
    if (this->_sig == true)
        throw Form::FormAlredySignedExeption();
    else if (other.getGrade() <= this->get_grade_sig())
        this->_sig = true;
    else
        throw Form::GradeTooLowException();
}

Form::~Form(){}

