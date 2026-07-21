#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
    if (argc != 2)
    {
        std::cout << "./executable \" Argument \"" << std::endl;
        return (0);
    }

    RPN rpn(argv[1]);
    rpn.calculate();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}