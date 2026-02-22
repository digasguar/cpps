#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("Default", 100, 100, 30)
{
    std::cout << "FragTrap Default constructor called" << std::endl; 
}

FragTrap::FragTrap(std::string name):ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap name constructor called" << std::endl; 
}
FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &FragTrap)
{
    if (&FragTrap != this)
    {
        std::cout  << "FragTrap "<< FragTrap._name << " copied into " << this->_name << std::endl;
        this->_name = FragTrap._name;
        this->_hp = FragTrap._hp;
        this->_ep = FragTrap._ep;
        this->_ad = FragTrap._ad;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this-> _name << " requests a positive high five " << std::endl;
}

void FragTrap::attack(ClapTrap &target)
{
    std::cout << "FragTrap powerfull attack!\n";
    ClapTrap::attack(target);
}