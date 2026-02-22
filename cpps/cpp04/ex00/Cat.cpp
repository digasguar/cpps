#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Default constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(Cat& other): Animal()
{
    std::cout << "Cat copy constructor" << std::endl;
    this->type = other.type;
}

Cat& Cat::operator=(Cat& other)
{
    if(this != &other)
        this->type = other.type;
    return(*this);
}

void  Cat::makeSound() const
{
    std::cout << "Miaaauuuuuuu!!!!!!" << std::endl;
}
