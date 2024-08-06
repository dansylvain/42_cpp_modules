#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void	getInput(std::string str, float *f)
{
	bool validInput = false;
	while (!validInput) {
		std::cout << str;
		std::cin >> *f;
		std::cout << "VALUE GIVEN: " << *f << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input. Please enter a valid floating point number." << std::endl;
		} 
		else
			validInput = true;
	}
}

void readPoint(Point &p) {
	float x, y;
	getInput("Enter x coordinate: ", &x);
	getInput("Enter y coordinate: ", &y);
	p = Point(x, y);
}


int main(void)
{
	Point a(0,0), b(10,0), c(0,10), point(1,2);

	std::cout << "Hello World !" << std::endl;
	std::cout << "Enter coordinates for triangle points:" << std::endl;
	std::cout << "Point 1 (a):" << std::endl;
	readPoint(a);
	std::cout << "Point 2 (b):" << std::endl;
	readPoint(b);
	std::cout << "Point 3 (c):" << std::endl;
	readPoint(c);
	std::cout << "Point to be tested (p):" << std::endl;
	readPoint(point);
	std::cout << "triangle point1: "	<< a.get_x().toFloat() 		<< " : " << a.get_y().toFloat() << std::endl;
	std::cout << "triangle point2: "	<< b.get_x().toFloat() 		<< " : " << b.get_y().toFloat() << std::endl;
	std::cout << "triangle point3: "	<< c.get_x().toFloat() 		<< " : " << c.get_y().toFloat() << std::endl;
	std::cout << "point to be tested: "	<< point.get_x().toFloat() 	<< " : " << point.get_y().toFloat() << std::endl;
	
	bsp(a, b, c, point) ? std::cout << "YES!" : std::cout << "NO!";
	
	std::cout << std::endl;
	return (0);
}