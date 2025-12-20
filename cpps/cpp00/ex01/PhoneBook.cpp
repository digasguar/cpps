#include "PhoneBook.hpp"
#include <iomanip>

    void  Phonebook::addContact()
    {
        Contact* newcontact = new Contact();

        if(this->contacts[this->numContacts % 8] != NULL)
            delete this->contacts[this->numContacts % 8];
        this->contacts[this->numContacts % 8] = newcontact;
        this->numContacts++;
    }

    std::string truncate(std::string str)
    {
        if (str.length() > 10)
        {
            str = str.substr(0,9);
            str.append(".");
        }
        return (str);
    }

    void Phonebook::search(std::string command)
    {
        bool found = false;
        
        for (int i = 0; contacts[i] && i < 8; i++)
        {
            if(contacts[i]->getFirstName().find(command) != std::string::npos)
            {
                if (!found)
                {
                    std::cout << std::setw(10) << std::right << "Index"
                    << "|" << std::setw(10) << std::right << "First Name"
                    << "|" << std::setw(10) << std::right << "Last Name"
                    << "|" << std::setw(10) << std::right << "Nickname" << "\n";
                    found = true;
                }
                std::cout << std::setw(10) << std::right << i
                << "|" << std::setw(10) << std::right << truncate(contacts[i]->getFirstName())
                << "|" << std::setw(10) << std::right << truncate(contacts[i]->getLastName())
                << "|" << std::setw(10) << std::right << truncate(contacts[i]->getNickName()) << "\n";
            }
        }
        
        if (!found)
            std::cout << "no match found \n";
    }

    Phonebook::~Phonebook()
    {
        for (int i = 0; i < 8; ++i)
        {
            if (contacts[i] != NULL)
            {
                delete contacts[i];
                contacts[i] = NULL;
            }
        }
    }

    Phonebook::Phonebook()
    {
        for(int i = 0; i < 8 ; i++)
        {
            contacts[i] = NULL;
        }
        this->numContacts = 0;
        std::string command;
        while (1)
        {
            std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
            std::getline(std::cin, command);
            if (command == "ADD") {
                std::cout << "You chose to ADD.\n";
                addContact();
            } else if (command == "SEARCH") {
                std::cout << "You chose to SEARCH.\n";
                std::getline(std::cin, command);
                search(command);
            } else if (command == "EXIT") {
                std::cout << "Exiting the program...\n";
                this->~Phonebook();
                break;
            } else {
                std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n";
            }
        }
    }