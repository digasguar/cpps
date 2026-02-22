#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    FragTrap &operator=(const FragTrap &fragTrap);
    void attack(ClapTrap &target);
    void highFivesGuys();
    ~FragTrap();
};
