#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point(void);
    Point(float const x, float const y);
    Point(Point const &other);
    Point &operator=(Point const &other);
    ~Point(void);

    Fixed const &getX(void) const;
    Fixed const &getY(void) const;
};

#endif