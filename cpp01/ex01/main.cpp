
#include "Zombie.hpp"

int main(void)
{
    Zombie *z = zombieHorde(15, "alberto");
    delete [] z;
}