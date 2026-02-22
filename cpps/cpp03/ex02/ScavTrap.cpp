#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("Default", 100, 50, 20)
{
    std::cout << "ScavTrap Default constructor called" << std::endl; 
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap name constructor called" << std::endl; 
}
ScavTrap::ScavTrap(const ScavTrap& ScavTrap) : ClapTrap(ScavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ScavTrap)
{
    if (&ScavTrap != this)
    {
        std::cout  << "ScavTrap "<< ScavTrap._name << " copied into " << this->_name << std::endl;
        this->_name = ScavTrap._name;
        this->_hp = ScavTrap._hp;
        this->_ep = ScavTrap._ep;
        this->_ad = ScavTrap._ad;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this-> _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(ClapTrap &target)
{
    std::cout << "ScavTrap special attack!\n";
    ClapTrap::attack(target);
}