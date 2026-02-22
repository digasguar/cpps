#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat& other);
    Cat& operator=(Cat& other);
    void makeSound()const;
    ~Cat();
};