#ifndef WANIMAL_H
# define WANIMAL_H
# include <string>
# include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal& other);
    WrongAnimal& operator=(WrongAnimal& other);
    virtual ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};
#endif

