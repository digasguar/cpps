#include "Fixed.hpp"


Fixed::Fixed(): RawBits(0){}


Fixed::Fixed(const int i): RawBits(i << FractionalBits){}

Fixed::Fixed(const float i): RawBits((int)roundf(i *(1  << FractionalBits))){}


Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    this->RawBits = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
    return(this->RawBits);
}

void Fixed::setRawBits( int const raw )
{
    this->RawBits = raw;
}


std::ostream	&operator<<(std::ostream &out, const Fixed &Fixed)
{
    out << Fixed.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->getRawBits() < other.getRawBits())
    {
        return(true);
    }
    return(false);
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
    {
        return(true);
    }
    return(false);
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->getRawBits() <= other.getRawBits())
    {
        return(true);
    }
    return(false);
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->getRawBits() >= other.getRawBits())
    {
        return(true);
    }
    return(false);
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->getRawBits() != other.getRawBits())
    {
        return(true);
    }
    return(false);
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->getRawBits() == other.getRawBits())
    {
        return(true);
    }
    return(false);
}

int		Fixed::toInt(void) const 
{
    return ((int)(roundf((float)this -> RawBits / (1 << this -> FractionalBits)))); 
}

float	Fixed::toFloat(void) const 
{
    return((float)this -> RawBits / (1 << this -> FractionalBits)); 
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->RawBits + other.RawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->RawBits - other.RawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long temp = (long)this->RawBits * other.RawBits;
    result.setRawBits(temp >> FractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long temp = ((long)this->RawBits << FractionalBits) / other.RawBits;
    result.setRawBits(temp);
    return result;
}

Fixed& Fixed::operator++()
{
    this->RawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->RawBits++;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->RawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->RawBits--;
    return temp;
}

const Fixed&	Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed2);
	return (fixed1);
}

Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed2);
	return (fixed1);
}

const Fixed&	Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}