#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		// Constructors & destructors
		Point();
		Point(const float x, const float y);
		Point(Fixed const point);
		Point& operator=(const Point& src);
		~Point();
};
