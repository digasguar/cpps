#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Bob");
	ClapTrap b("Enemy");
	std::cout << b.getHp() << std::endl;
	b.beRepaired(30);
	std::cout << b.getHp() << std::endl;
	a.attack(b);
	std::cout << b.getHp() << std::endl;
	a.attack(b);
	std::cout << b.getHp() << std::endl;
	a.attack(b);
	std::cout << b.getHp() << std::endl;
	a.attack(b);
	std::cout << b.getHp() << std::endl;
	b.attack(a);
	std::cout << a.getHp() << std::endl;
	b.beRepaired(30);
}