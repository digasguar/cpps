#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

char customToUpper(char c) {
    switch (c) {
        case -79: // ñ -> Ñ
            return -111;
        case -96: // à -> À
            return -128;
        case -95: // á -> Á
            return -127;
        case -87: // é -> É
            return -119;
        case -83: // í -> Í
            return -115;
        case -77: // ó -> Ó
            return -109;
        case -70: // ú -> Ú
            return -102;
        case -68: // ü -> Ü
            return -100;
        default:
            if (c >= 'a' && c <= 'z') {
                return toupper(c);
            }
            return c;
    }
}

int main(int argc, char* argv[]) 
{
    if (argc > 1) {
        for (int j = 1; j < argc;j++)
        {
            std::string input(argv[j]);
            for (size_t i = 0; i < strlen(argv[j]);i++) {
                input[i] = customToUpper(argv[j][i]);
            }
            std::cout << input ;
            if (j < argc-1)
                std::cout << " ";
        }
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }

    return 0;
}

