#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name("Default"),_hp(10),_ep(10) ,_ad(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl; 
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad):_name(name),_hp(hp),_ep(ep),_ad(ad)
{
    std::cout << "ClapTrap Not Default constructor called" << std::endl; 
}


ClapTrap::ClapTrap(std::string name):_name(name),_hp(10),_ep(10),_ad(0)
{
    std::cout << "ClapTrap name constructor called" << std::endl; 
}
ClapTrap::ClapTrap(const ClapTrap& clapTrap):_name(clapTrap._name),_hp(clapTrap._hp),_ep(clapTrap._ep),_ad(clapTrap._ad)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap clapTrap)
{
    if (&clapTrap != this)
    {
        std::cout  << "ClapTrap "<< clapTrap._name << " copied into " << this->_name << std::endl;
        this->_name = clapTrap._name;
        this->_hp = clapTrap._hp;
        this->_ep = clapTrap._ep;
        this->_ad = clapTrap._ad;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(ClapTrap& target)
{
    if (_hp <= 0)
    {
        std::cout << "ClapTrap " << _name 
                  << " cannot attack because it has no hit points\n";
        return;
    }
    if (_ep <= 0)
    {
        std::cout << "ClapTrap " << _name 
                  << " has no energy points left\n";
        return;
    }
    _ep--;
    std::cout << "ClapTrap " << _name 
              << " attacks " << target._name 
              << ", causing " << _ad 
              << " points of damage!\n";

    target.takeDamage(_ad);
}

void ClapTrap::takeDamage(unsigned int amount)
{
   if (amount >= (unsigned int)_hp)
        _hp = 0;
    else
        _hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hp <= 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair because it has no hit points\n";
        return;
    }
    if (_ep <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left\n";
        return;
    }

    _ep--;
    _hp += amount;

    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!\n";
}

int ClapTrap::getHp()
{
    return(this->_hp);
}