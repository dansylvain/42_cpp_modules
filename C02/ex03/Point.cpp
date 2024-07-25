#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Fixed const point) {

}

Point& Point::operator=(const Point& src) {

}

Point::~Point() {

}
