#include <string>
#include <iostream>

class ClapTrap
{
private:
    std::string Name_;
    int Hp_;
    int Ep_;
    int Ad_;
public:
    ClapTrap();
    ClapTrap(ClapTrap& clapTrap);
    ClapTrap(std::string name);
    ClapTrap &operator=(const ClapTrap clapTrap);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};