#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate()
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }
    int r = rand() % 3;
    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    return (new C);
}

void identify(Base *p)
{
    if (p == NULL)
    {
        std::cout << "Null ptr" << std::endl;
        return ;
    }
    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "C\n";
}

void identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(&p))
        std::cout << "B\n";
    else if (dynamic_cast<C *>(&p))
        std::cout << "C\n";
} 
