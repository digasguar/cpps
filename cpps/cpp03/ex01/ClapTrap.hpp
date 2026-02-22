#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int _hp;
    int _ep;
    int _ad;
public:
    ClapTrap();
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap(std::string name);
    ClapTrap &operator=(const ClapTrap clapTrap);
    ClapTrap(std::string name, int hp, int ep, int ad);
    ~ClapTrap();

    void attack(ClapTrap& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int getHp(void);
};
#endif