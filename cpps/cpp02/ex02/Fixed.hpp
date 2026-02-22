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
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    //pre
    Fixed& operator++();
    Fixed& operator--();

    //post
    Fixed operator++(int);
    Fixed operator--(int);


    static Fixed& min(Fixed &fixed1, Fixed &fixed2);
    static const Fixed&	min(const Fixed &fixed1, const Fixed &fixed2);

    static Fixed& max(Fixed &fixed1, Fixed &fixed2);
    static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);



    ~Fixed();
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits( int const raw );
};
std::ostream	&operator<<(std::ostream &out, const Fixed &Fixed);