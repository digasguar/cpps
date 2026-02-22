#include <strings.h>
#include <iostream>

class Fixed
{
private:
    int RawBits;
    static const int FractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits( int const raw );
};