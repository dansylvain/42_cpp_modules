#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& src)  : _x(src._x), _y(src._y)  {}

Point& Point::operator=(const Point& src) {
	if (this != &src)
	{
		_x.setRawBits(src._x.getRawBits());
		_y.setRawBits(src._y.getRawBits());
	}
	return (*this);
}

Point::~Point() {}
