#include "Hearl.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
        return(0);
    Hearl hearl;
    hearl.complain(argv[1]);
}