#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data d;
    d.number = 42;
    d.text = "asdsfasd";

    Data* ptr = &d;

    uintptr_t ptr1 = Serializer::serialize(ptr);
    Data* ptr2 = Serializer::deserialize(ptr1);

    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "Deserialized: " << ptr2 << std::endl;

    std::cout << "Number: " << ptr2->number << std::endl;
    std::cout << "Text:   " << ptr2->text << std::endl;

    if (ptr == ptr2)
        std::cout << "OK" << std::endl;
    return (0);
}