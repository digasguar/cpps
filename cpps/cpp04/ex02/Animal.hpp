#ifndef ANIMAL_H
# define ANIMAL_H
# include <string>
# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal& other);
    Animal& operator=(Animal& other);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    std::string getType() const;
};
#endif