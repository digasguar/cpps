#ifndef Contact_HPP
# define Contact_HPP

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

class Contact
{
    public:
        Contact();
        ~Contact();
        void    setFirstName(const std::string  first_name);
        void    setLast_name(const std::string  last_name);
        void    setNickname(const std::string  nickname);
        void    setDark_secret(const std::string  dark_secret);
        void    setPhone_number(const std::string  phoneNumber);
        std::string    getFirstName();
        std::string    getLastName();
        std::string    getNickName();
    protected:
        std::string firts_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string dark_secret;

};

#endif