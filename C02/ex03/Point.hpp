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
	Point(const float x, const float y);
	Point(Point const &point);
	~Point();

	
	// Access and utility methods
	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
	
	// Assignment operator
	Point &operator=(const Point &src);
	
	// more useful methods to be added
};

#endif