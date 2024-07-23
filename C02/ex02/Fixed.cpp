#include "Fixed.hpp"


Fixed::Fixed() : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int integer) {
	// std::cout << "Int constructor called" << std::endl;
	_value = integer << _fractionalBits;
}

Fixed::Fixed(const float floatingPoint) {
	// std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)));
}

Fixed &Fixed::operator=(const Fixed &fixed){
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->_value = fixed.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;

}

void	Fixed::setRawBits(int const raw){
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;

}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator==(const Fixed &other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _value != other._value;
}

bool Fixed::operator>(const Fixed &other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _value <= other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result._value = (static_cast<long long>(_value) * other._value) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other._value == 0)
		throw std::runtime_error("Division by zero");
	Fixed result;
	result._value = (static_cast<long long>(_value) << _fractionalBits) / other._value;
	return result;
}

Fixed& Fixed::operator++() {
	++_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_value;
	return temp;
}

Fixed& Fixed::operator--() {
	--_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_value;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a._value < b._value) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a._value < b._value) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a._value > b._value) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a._value > b._value) ? a : b;
}