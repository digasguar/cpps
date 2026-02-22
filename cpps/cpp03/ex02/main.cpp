#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap c("Clappy");
    ScavTrap s("Scavy");
    FragTrap f("Fraggy");


    f.attack(c);
    std::cout << "Clappy HP: " << c.getHp() << std::endl;
    f.highFivesGuys();

    FragTrap f2 = f;
    FragTrap f3;
    f3 = f;
}