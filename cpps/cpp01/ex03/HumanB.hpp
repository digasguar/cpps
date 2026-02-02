#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name, Weapon& weapon);
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon& weapon);
    private:
        std::string name;
        Weapon* weapon;
       
};
