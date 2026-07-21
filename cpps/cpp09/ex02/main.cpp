#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "./program (arguments)"<<std::endl;
        return(0);
    }
    if (!validateInput(argv))
    {
        std::cout << "onli numbers plis"<<std::endl;
        return (0);
    }
    PmergeMe *a = new PmergeMe(argc, argv);
    delete a;
}