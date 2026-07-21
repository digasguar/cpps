#include "AForm.hpp"

class Intern
{
public:
    class FormNotExist : public std::exception
    {
        virtual const char* what() const throw();
    };
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();
    AForm* makeForm(std::string name, std::string target); 
};
AForm* createShrubbery(std::string target);
AForm* createRobotomy(std::string target);
AForm* createPresidential(std::string target);