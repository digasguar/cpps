#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    std::cout << "zombie created..."<<std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << ": destroy" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}