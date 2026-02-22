#include "Fixed.hpp"


Fixed::Fixed(): RawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i): RawBits(i << FractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float i): RawBits((int)roundf(i *(1  << FractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->RawBits = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->RawBits);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->RawBits = raw;
}


std::ostream	&operator<<(std::ostream &out, const Fixed &Fixed)
{
    out << Fixed.toFloat();
	return out;
}

int		Fixed::toInt(void) const 
{
    return ((int)(roundf((float)this -> RawBits / (1 << this -> FractionalBits)))); 
}

float	Fixed::toFloat(void) const 
{
    return((float)this -> RawBits / (1 << this -> FractionalBits)); 
}