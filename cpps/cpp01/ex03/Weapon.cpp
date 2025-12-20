#include "Weapon.hpp"


const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(const std::string& s)
{
    this->type = s;
}