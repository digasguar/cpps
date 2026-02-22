#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << this->name;
    std::cout << " attacks with their ";
    if (weapon != NULL)
        std::cout << weapon->getType() <<std::endl;
    else
        std::cout << "empty hands" <<std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name, Weapon& weapon) : name(name), weapon(&weapon)
{
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}