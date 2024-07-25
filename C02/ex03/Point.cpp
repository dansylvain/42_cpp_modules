#include "Point.hpp"
#include "Fixed.hpp"
	
/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(Point const &point) {
	*this = point;}

Point::~Point() {};

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Point &Point::operator=(const Point &src) {
	if (this != &src)
	{
		this->x = src.getX();
		this->y = src.getY();
	}
	return *this;}

/**========================================================================
 *                           ACCESS AND UTILITY METHODS
 *========================================================================**/
const Fixed& Point::getX(void) const {
	return this->x;
}

const Fixed& Point::getY(void) const {
	return this->y;
}
