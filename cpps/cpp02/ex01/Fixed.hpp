#include <strings.h>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int RawBits;
    static const int FractionalBits = 8;
public:
    Fixed();
    Fixed(const int i);
    Fixed(const float i);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits( int const raw );
};
std::ostream	&operator<<(std::ostream &out, const Fixed &Fixed);