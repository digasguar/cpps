#include "Hearl.hpp"

int main (void)
{
    Hearl hearl;

    std::cout << "Testing DEBUG level:" << std::endl;
    hearl.complain("DEBUG");

    std::cout << "\nTesting INFO level:" << std::endl;
    hearl.complain("INFO");

    std::cout << "\nTesting WARNING level:" << std::endl;
    hearl.complain("WARNING");

    std::cout << "\nTesting ERROR level:" << std::endl;
    hearl.complain("ERROR");

    std::cout << "\nTesting invalid level:" << std::endl;
    hearl.complain("unknown"); 
}