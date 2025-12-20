#include <iostream>
#include "Contact.hpp"

class Phonebook
{   
    public:

        Phonebook();
        ~Phonebook();
        void  addContact();
        void  search(std::string command);
    private:
        bool primaryKey(std::string str);
        Contact* contacts[8];
        int numContacts;
};