#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0) {}

Fixed::Fixed(Fixed const &other) {
  this->_fixedPointValue = other.getRawBits();
}

Fixed::Fixed(int const n) { this->_fixedPointValue = n << _fractionalBits; }

Fixed::Fixed(float const f) {
  this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(Fixed const &other) {
  if (this != &other)
    this->_fixedPointValue = other.getRawBits();
  return *this;
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const {
  return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
  return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(Fixed const &other) const {
  return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(Fixed const &other) const {
  return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(Fixed const &other) const {
  return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(Fixed const &other) const {
  return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(Fixed const &other) const {
  return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(Fixed const &other) const {
  return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(Fixed const &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) {
  this->_fixedPointValue += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  this->_fixedPointValue += 1;
  return tmp;
}

Fixed &Fixed::operator--(void) {
  this->_fixedPointValue -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->_fixedPointValue -= 1;
  return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
  return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
  os << fixed.toFloat();
  return os;
}
