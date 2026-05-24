#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other.getRawBits();
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(Fixed const &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

/* Comparison operators */
bool Fixed::operator>(Fixed const &other) const
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(Fixed const &other) const
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(Fixed const &other) const
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(Fixed const &other) const
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(Fixed const &other) const
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(Fixed const &other) const
{
    return this->_fixedPointValue != other._fixedPointValue;
}

/* Arithmetic operators */
Fixed Fixed::operator+(Fixed const &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

/* Increment/Decrement */
Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue += 1;  // smallest epsilon: 1/256 = 0.00390625
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_fixedPointValue += 1;  // smallest epsilon: 1/256 = 0.00390625
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue -= 1;  // smallest epsilon: 1/256 = 0.00390625
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_fixedPointValue -= 1;  // smallest epsilon: 1/256 = 0.00390625
    return tmp;
}

/* Static min/max */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
}