#include "Fixed.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {
	*this = fixed;}

Fixed::Fixed(const int integer) {
	_value = integer << _fractionalBits;}

Fixed::Fixed(const float floatingPoint) {
	_value = static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)));}

Fixed::~Fixed() {}

/**========================================================================
 *                        ACCESS AND UTILITY METHODS
 *========================================================================**/
int		Fixed::getRawBits(void) const{
	return this->_value;}

void	Fixed::setRawBits(int const raw){
	this->_value = raw;}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;}

/**========================================================================
 *                           MIN AND MAX METHODS
 *========================================================================**/
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a._value < b._value) ? a : b;}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a._value < b._value) ? a : b;}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a._value > b._value) ? a : b;}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a._value > b._value) ? a : b;}

/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;}

/**========================================================================
 *                    COMPARISON OPERATORS
 *========================================================================**/
bool Fixed::operator==(const Fixed &other) const {
	return _value == other._value;}

bool Fixed::operator!=(const Fixed &other) const {
	return _value != other._value;}

bool Fixed::operator>(const Fixed &other) const {
	return _value > other._value;}

bool Fixed::operator<(const Fixed &other) const {
	return _value < other._value;}

bool Fixed::operator>=(const Fixed &other) const {
	return _value >= other._value;}

bool Fixed::operator<=(const Fixed &other) const {
	return _value <= other._value;}

/**========================================================================
 *                    ARITHMETIC OPERATORS
 *========================================================================**/
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result._value = _value + other._value;
	return result;}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result._value = _value - other._value;
	return result;}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result._value = (static_cast<long long>(_value) * other._value) >> _fractionalBits;
	return result;}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other._value == 0)
		throw std::runtime_error("Division by zero");
	Fixed result;
	result._value = (static_cast<long long>(_value) << _fractionalBits) / other._value;
	return result;}

/**========================================================================
 *                     INCREMENT AND DECREMENT OPERATORS
 *========================================================================**/
Fixed& Fixed::operator++() {
	++_value;
	return *this;}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_value;
	return temp;}

Fixed& Fixed::operator--() {
	--_value;
	return *this;}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_value;
	return temp;}

/**========================================================================
 *                         OVERLOAD OF << OPERATOR
 * onverts fixed point number to float and forward it to output stream.
 *========================================================================**/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;}