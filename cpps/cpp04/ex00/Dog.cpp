#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(Dog& other):Animal()
{
    std::cout << "Dog copy constructor" << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(Dog& other)
{
   if(this != &other)
        this->type = other.type;
    return(*this);
}

void  Dog::makeSound() const
{
    std::cout << "Gauuuu!!!!!!" << std::endl;
}
