#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed(void);
    Fixed(Fixed const &other);
    Fixed(int const n);
    Fixed(float const f);
    Fixed &operator=(Fixed const &other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif