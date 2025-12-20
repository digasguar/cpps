#include <string>
#include <iostream>

class Weapon
{
    public:
        const std::string& getType(); 
        void setType(const std::string& s);
    private:
        std::string type;
};
