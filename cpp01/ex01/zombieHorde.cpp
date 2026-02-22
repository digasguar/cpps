
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (!N || N < 1)
        return NULL;
    Zombie *z = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        z[i].setName(name);
    }
    return (z);
}