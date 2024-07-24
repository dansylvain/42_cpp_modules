#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;
	// more useful attributes to be added
public:
	// Constructors and destructor
	Point();
	Point(Fixed const x, Fixed const y);
	Point(Point const &point);
	~Point();

	// Assignment operator
	Point &operator=(const Point &src);

	// overloading of << operator
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
	
	// more useful methods to be added
};

#endif