#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;
public:
    Dog();
    Dog(Dog& other);
    Dog& operator=(Dog& other);
    void makeSound()const;
    ~Dog();
};