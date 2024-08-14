#include "Fixed.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	_value = integer << _fractionalBits;
}

Fixed::Fixed(const float floatingPoint)
{
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return *this;
}

/**========================================================================
 *                        ACCESS AND UTILITY METHODS
 *========================================================================**/
int		Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

/**========================================================================
 *                         OVERLOAD OF << OPERATOR
 * onverts fixed point number to float and forward it to output stream.
 *========================================================================**/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}