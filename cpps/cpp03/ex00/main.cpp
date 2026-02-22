#include "ClapTrap.hpp"

int main()
{
	ClapTrap andres("Andres");
	ClapTrap samuel("Samuel");
	ClapTrap foreign;
	foreign = samuel;

	andres.attack("Samuel");
	samuel.takeDamage(0);
	samuel.takeDamage(132);
	samuel.attack("Me");
	samuel.beRepaired(2);
	samuel.takeDamage(10);
	foreign.attack("Andres");
	return 0;
}