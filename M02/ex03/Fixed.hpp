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

    /* Comparison operators */
    bool operator>(Fixed const &other) const;
    bool operator<(Fixed const &other) const;
    bool operator>=(Fixed const &other) const;
    bool operator<=(Fixed const &other) const;
    bool operator==(Fixed const &other) const;
    bool operator!=(Fixed const &other) const;

    /* Arithmetic operators */
    Fixed operator+(Fixed const &other) const;
    Fixed operator-(Fixed const &other) const;
    Fixed operator*(Fixed const &other) const;
    Fixed operator/(Fixed const &other) const;

    /* Increment/Decrement */
    Fixed &operator++(void);       // pre-increment
    Fixed operator++(int);         // post-increment
    Fixed &operator--(void);       // pre-decrement
    Fixed operator--(int);         // post-decrement

    /* Static min/max */
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif