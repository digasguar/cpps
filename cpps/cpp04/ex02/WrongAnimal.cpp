#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal Default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other)
{
    if(this != &other)
        this->type = other.type;
    return(*this);
}

void  WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makeSound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}