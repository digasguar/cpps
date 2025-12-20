
#include "Zombie.hpp"

int main(void)
{
    Zombie *z = newZombie("pepe");
    z->announce();
    Zombie *z1  = new Zombie("juan");
    z1->announce();
    delete (z);
    delete (z1);
    randomChump("zombie 1");

}