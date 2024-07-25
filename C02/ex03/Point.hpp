#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		// Constructors & destructors
		Point();
		Point(const float x, const float y);
		Point(Fixed const point);
		Point& operator=(const Point& src);
		~Point();
};
