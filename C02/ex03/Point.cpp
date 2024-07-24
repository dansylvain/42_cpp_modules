#include "Point.hpp"

	
// Constructors and destructor
Point::Point() : x(0), y(0) {}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {}

Point::Point(Point const &point) {
	*this = point;
}

Point::~Point() {};


// je me retrouve emmerdé, parce que je ne peux pas assigner de valeur à x et y, car ce sont des const
// je ne peux pas non plus les modifier dans le constructeur, car ce sont des const
// je ne peux pas non plus les modifier dans l'opérateur d'assignation, car ce sont des const
// donc, c'est la merde

// Assignment operator
Point &Point::operator=(const Point &src) {
	if (this != &src)
	{
		this.x
	}
		this->_value = src.getRawBits();
	return *this;}

// overloading of << operator	
friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
