#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		// Constructors & destructors
		Point();
		Point(const float x, const float y);
		Point(const Point& src);
		~Point();
		
		// assignment operator
		Point& operator=(const Point& src);

		// access and utility methods
		const Fixed& get_x(void) const;
		const Fixed& get_y(void) const;

		// others...
};

#endif