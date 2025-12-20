#include "Contact.hpp"

    bool isNumber(const std::string& str) {
        return str.find_first_not_of("0123456789") == std::string::npos;
    }

    bool isAscii(const std::string& str)
    {
        for (std::string::size_type i = 0; i < str.length(); ++i)
        {
            unsigned char c = static_cast<unsigned char>(str[i]);
            if (c < 32 || c > 126)
                return false;
        }
        return true;
    }

    Contact::Contact()
    {
        std::string str;

        while (true) {
            std::cout << "Put your first name: ";
            std::getline(std::cin, str);
            if (!str.empty() && isAscii(str)) {
                setFirstName(str);
                break;
            } else {
                std::cout << "First name cannot be empty. Please try again.\n";
            }
        }


        while (true) {
            std::cout << "Put your last name: ";
            std::getline(std::cin, str);
            if (!str.empty() && isAscii(str)) {
                setLast_name(str);
                break;
            } else {
                std::cout << "Last name cannot be empty. Please try again.\n";
            }
        }


        while (true) {
            std::cout << "Put your nickname: ";
            std::getline(std::cin, str);
            if (!str.empty() && isAscii(str)) {
                setNickname(str);
                break;
            } else {
                std::cout << "Nickname cannot be empty. Please try again.\n";
            }
        }

        while (true) {
            std::cout << "Put your phone number (9 digits): ";
            std::getline(std::cin, str);
            if (str.length() == 9 && isNumber(str)) {
                setPhone_number(str);
                break;
            } else {
                std::cout << "Invalid phone number. It must be 9 digits long and contain only numbers. Please try again.\n";
            }
        }


        while (true) {
            std::cout << "Put your dark secret: ";
            std::getline(std::cin, str);
            if (!str.empty() && isAscii(str)) {
                setDark_secret(str);
                break;
            } else {
                std::cout << "Dark secret cannot be empty. Please try again.\n";
            }
        }
    }

    void    Contact::setFirstName(const std::string firts_name)
    {
        this->firts_name = firts_name;
    }

    void    Contact::setLast_name(const std::string  last_name)
    {
        this->last_name = last_name;
    }

    void    Contact::setNickname(const std::string nickname)
    {
        this->nickname = nickname;
    }

    void    Contact::setDark_secret(const std::string  dark_secret)
    {
        this->dark_secret = dark_secret;
    }

    void    Contact::setPhone_number(const std::string  phoneNumber)
    {
        this->phone_number = phoneNumber;
    }

    std::string Contact::getFirstName()
    {
        return (this->firts_name);
    }
    std::string    Contact::getLastName()
    {
        return (this->last_name);
    }
    std::string    Contact::getNickName()
    {
        return (this->nickname);
    }
    Contact::~Contact()
    {
        std::cout << "Contact destroyed!\n";
    }