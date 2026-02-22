#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Name_("Default"),Hp_(10),Ep_(10) ,Ad_(0)
{
    std::cout << "Default constructor called" << std::endl; 
}

ClapTrap::ClapTrap(std::string name):Name_(name),Hp_(10),Ep_(10),Ad_(0)
{
    std::cout << "name constructor called" << std::endl; 
}
ClapTrap::ClapTrap(ClapTrap& clapTrap):Name_(clapTrap.Name_),Hp_(clapTrap.Hp_),Ep_(clapTrap.Ep_),Ad_(clapTrap.Ad_)
{
    std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap clapTrap)
{
    if (&clapTrap != this)
    {
        std::cout  << clapTrap.Name_ << " copied into " << this->Name_ << std::endl;
        this->Name_ = clapTrap.Name_;
        this->Hp_ = clapTrap.Hp_;
        this->Ep_ = clapTrap.Ep_;
        this->Ad_ = clapTrap.Ad_;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hp_ <= 0)
    {
        std::cout << "ClapTrap " << Name_ << " cannot attack because it has no hit points\n";
        return;
    }
    if (Ep_ <= 0)
    {
        std::cout << "ClapTrap " << Name_ << " has no energy points left\n";
        return;
    }
    Ep_--;
    std::cout << "ClapTrap " << Name_ << " attacks " << target << ", causing " << Ad_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hp_ <= 0)
    {
        std::cout << "ClapTrap " << Name_ << " has no hit points left\n";
        return;
    }

    Hp_ -= amount;
    if (Hp_ < 0)
        Hp_ = 0;

    std::cout << "ClapTrap " << Name_ << " takes " << amount << " damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hp_ <= 0)
    {
        std::cout << "ClapTrap " << Name_ << " cannot repair because it has no hit points\n";
        return;
    }
    if (Ep_ <= 0)
    {
        std::cout << "ClapTrap " << Name_ << " has no energy points left\n";
        return;
    }

    Ep_--;
    Hp_ += amount;

    std::cout << "ClapTrap " << Name_ << " repairs itself for " << amount << " hit points!\n";
}
