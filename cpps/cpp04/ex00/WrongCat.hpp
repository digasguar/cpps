#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(WrongCat& other);
    WrongCat& operator=(WrongCat& other);
    void makeSound()const;
    ~WrongCat();
};