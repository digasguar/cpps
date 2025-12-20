#include <string>


class Zombie
{
    public:
    Zombie(std::string n);
    ~Zombie();
    void announce( void );

    private:
    std::string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
