#include "Dog.hpp"

Dog::Dog():Animal(), brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog Default constructor" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(Dog& other):Animal(), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor" << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(Dog& other)
{
    if(this != &other)
    {
        this->type = other.type;
        *brain = *other.brain;
    }       
    return(*this);
}

void  Dog::makeSound() const
{
    std::cout << "Gauuuu!!!!!!" << std::endl;
}
