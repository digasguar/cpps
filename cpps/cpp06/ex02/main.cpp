#include "Base.hpp"

int main() {
    for (int i = 0; i < 10; i++) {
        Base* obj = generate();

        identify(obj);
        identify(*obj);

        delete obj;
        std::cout << "----\n";
    }

    return 0;
}