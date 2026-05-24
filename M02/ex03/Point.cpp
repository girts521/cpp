#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const &other) : _x(other.getX()), _y(other.getY())
{
}

Point &Point::operator=(Point const &other)
{
    if (this != &other)
    {
        const_cast<Fixed &>(this->_x) = other.getX();
        const_cast<Fixed &>(this->_y) = other.getY();
    }
    return *this;
}

Point::~Point(void)
{
}

Fixed const &Point::getX(void) const
{
    return this->_x;
}

Fixed const &Point::getY(void) const
{
    return this->_y;
}