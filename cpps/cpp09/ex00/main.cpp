#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "./executable <file>" << std::endl;
            return (0);
        }
        BitcoinExchange bitcoin(argv[1]);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
