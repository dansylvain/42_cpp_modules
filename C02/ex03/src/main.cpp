#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void	getInput(std::string str, float *f)
{
	bool validInput = false;
	while (!validInput) {
		std::cout << str;
		std::cin >> *f;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "INVALID INPUT. Please enter a valid number." << std::endl;
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

void	print(std::string str)
{
	std::cout << str << std::endl;
}




void	fire( Point const a, Point const b, Point const c, Point const point )
{	
	std::cout << "point= " << point.get_x() << ", " << point.get_y() << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "\033[32m 👌 You are in the triangle mg !\033[0m"
			<< std::endl << std::endl;
	else
		std::cout << "\033[33m ✍️ try again !\033[0m"
			<< std::endl << std::endl;
}

void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

int main( void )
{
	Point a(2, 1);
	Point b(6, 4);
	Point c(8, 1);
	
	printB("First tests: ");
	std::cout << "a= " << a.get_x() << ", " << a.get_y() << std::endl;
	std::cout << "b= " << b.get_x() << ", " << b.get_y() << std::endl;
	std::cout << "c= " << c.get_x() << ", " << c.get_y() << std::endl
		<< std::endl;
		
	{		
		Point point(5, 2.5);
		fire(a, b, c, point);
	}
	{
		Point point(7, 2);
		fire(a, b, c, point);
	}
	{
		Point point(7, 0);
		fire(a, b, c, point);
	}
	{
		Point point(7, 1);
		fire(a, b, c, point);
	}
	{
		Point point(7, 1.01);
		fire(a, b, c, point);
	}
	{
		Point point(3, 3);
		fire(a, b, c, point);
	}
	{
		Point point(-3, -3);
		fire(a, b, c, point);
	}
	{
		Point point(2, 1);
		fire(a, b, c, point);
	}
	{
		Point point(2.1, 1.01);
		fire(a, b, c, point);
	}
	pause();
	{
		Point a(0,0), b(10,0), c(0,10), point(1,2);
		printB("second test (your own)");
		print("");
		print("Enter coordinates for triangle points:");
		print("");
		print("Point 1 (a):");
		readPoint(a);
		print("");
		print("Point 2 (b):");
		readPoint(b);
		print("");
		print("Point 3 (c):");
		readPoint(c);
		print("");
		print("Point to be tested (p):");
		readPoint(point);
		print("");
		std::cout << "triangle point1: x: "	<< a.get_x().toFloat() 		<< " , y: " << a.get_y().toFloat() << std::endl;
		std::cout << "triangle point2: x: "	<< b.get_x().toFloat() 		<< " , y: " << b.get_y().toFloat() << std::endl;
		std::cout << "triangle point3: x: "	<< c.get_x().toFloat() 		<< " , y: " << c.get_y().toFloat() << std::endl;
		std::cout << "point to be tested: x: "	<< point.get_x().toFloat() 	<< " , y: " << point.get_y().toFloat() << std::endl;
		print("");
		if (bsp(a, b, c, point))
			std::cout << "\033[32m 👌 You are in the triangle mg !\033[0m";
		else
			std::cout << "\033[33m ✍️ try again !\033[0m";
		std::cout << std::endl;
	}
	return 0;
}