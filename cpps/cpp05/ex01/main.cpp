#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void)
{
    try
    {
        Bureaucrat a("diego",1);
        Form b("Form 1",150,2);
        b.beSigned(a);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        a.signForm(b);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("david",1);
        Form d("Form 2",150,2);
        std::cout << c << std::endl;
        std::cout << d << std::endl;
        c.signForm(d);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}
