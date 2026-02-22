#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(WrongCat& other): WrongAnimal()
{
    std::cout << "WrongCat copy constructor" << std::endl;
    this->type = other.type;
}

WrongCat& WrongCat::operator=(WrongCat& other)
{
    if(this != &other)
        this->type = other.type;
    return(*this);
}

void  WrongCat::makeSound() const
{
    std::cout << "Wrong Miaaauuuuuuu!!!!!!" << std::endl;
}
