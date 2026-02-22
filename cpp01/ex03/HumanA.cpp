#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << weapon->getType() <<std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(&weapon)
{
}

HumanA::~HumanA()
{
}
