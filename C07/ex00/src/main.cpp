#include "templateFunctions.hpp"

int main()
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "Tests from subject's main" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Test with type <int>" << std::endl;
		int x = 10, y = 20;
		std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
		swap(x, y);
		std::cout << "After  swap: x = " << x << ", y = " << y << std::endl;
		
		std::cout << "Min of 10 and 20: " << min(x, y) << std::endl;
		std::cout << "Max of 10 and 20: " << max(x, y) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Test with type <double>" << std::endl;
		double x = 15.5, y = 10.5;
		std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
		swap(x, y);
		std::cout << "After  swap: x = " << x << ", y = " << y << std::endl;
		std::cout << "Min of 15.5 and 10.5: " << min(x, y) << std::endl;
		std::cout << "Max of 15.5 and 10.5: " << max(x, y) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Test with type <char>" << std::endl;
		char a = 'A', b = 'B';
		std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "After  swap: a = " << a << ", b = " << b << std::endl;
		
		std::cout << "Min of 'A' and 'B': " << min(a, b) << std::endl;
		std::cout << "Max of 'A' and 'B': " << max(a, b) << std::endl;

	}
	return 0;
}