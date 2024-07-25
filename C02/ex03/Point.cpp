#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& src)  : _x(src._x), _y(src._y)  {}

Point& Point::operator=(const Point& src) {

}

Point::~Point() {

}
