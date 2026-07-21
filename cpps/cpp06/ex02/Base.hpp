#ifndef BASE_H
# define BASE_H
#include <ctime> 
#include <iostream>
#include <cstdlib>
#include <exception>

class Base
{
private:
public:
    virtual ~Base();
};
Base* generate(void);
void identify(Base* p);
void identify(Base& p);
#endif