#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal Default constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal(Animal& other)
{
    std::cout << "Animal copy constructor" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(Animal& other)
{
    if(this != &other)
        this->type = other.type;
    return(*this);
}

void  Animal::makeSound() const
{
    std::cout << "Animal makeSound" << std::endl;
}

std::string Animal::getType() const
{
    return(this->type);
}