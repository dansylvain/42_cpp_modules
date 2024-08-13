#include "templateFunctions.hpp"

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

int main()
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		printB("Tests from subject's main");
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
	pause();
	{
		printB("Test with type <int>");
		int x = 10, y = 20;
		std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
		swap(x, y);
		std::cout << "After  swap: x = " << x << ", y = " << y << std::endl;
		
		std::cout << "Min of 10 and 20: " << min(x, y) << std::endl;
		std::cout << "Max of 10 and 20: " << max(x, y) << std::endl;
	}
	pause();
	{
		printB("Test with type <double>");
		double x = 15.5, y = 10.5;
		std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
		swap(x, y);
		std::cout << "After  swap: x = " << x << ", y = " << y << std::endl;
		std::cout << "Min of 15.5 and 10.5: " << min(x, y) << std::endl;
		std::cout << "Max of 15.5 and 10.5: " << max(x, y) << std::endl;
	}
	pause();
	{
		printB("Test with type <char>");
		char a = 'A', b = 'B';
		std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "After  swap: a = " << a << ", b = " << b << std::endl;
		
		std::cout << "Min of 'A' and 'B': " << min(a, b) << std::endl;
		std::cout << "Max of 'A' and 'B': " << max(a, b) << std::endl;

	}
	return 0;
}