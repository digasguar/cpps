#include "Hearl.hpp"

Hearl::Hearl()
{
}

Hearl::~Hearl()
{
}


void Hearl::complain(std::string level)
{
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Hearl::*functions[4])() = {&Hearl::debug, &Hearl::info, &Hearl::warning, &Hearl::error};
    int i = 0;
    for(; options[i] != level && i < 4; i++);
    if (i == 4)
    {
        std::cout <<"[ Probably complaining about insignificant problems ]\n";
        return ;
    }
    for (; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            std::cout <<"[ DEBUG ]\n";
            break;
        case 1:
            std::cout <<"[ INFO ]\n";
            break;
        case 2:
            std::cout <<"[ WARNING ]\n";
            break;
        case 3:
            std::cout <<"[ ERROR ]\n";
            break;
        default:
            break;
        }
        (this->*functions[i])();
        std::cout << "\n";
    }
}


void Hearl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Hearl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Hearl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.\n";
}

void Hearl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}