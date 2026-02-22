#include "Cat.hpp"

Cat::Cat():Animal(), brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat Default constructor" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(Cat& other): Animal(), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(Cat& other)
{
    if(this != &other)
    {
        this->type = other.type;
        *brain = *other.brain;
    }
    return(*this);
}

void  Cat::makeSound() const
{
    std::cout << "Miaaauuuuuuu!!!!!!" << std::endl;
}
