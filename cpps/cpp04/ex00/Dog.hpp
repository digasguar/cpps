#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog& other);
    Dog& operator=(Dog& other);
    void makeSound()const;
    ~Dog();
};