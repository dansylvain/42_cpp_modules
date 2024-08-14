#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
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

int main() {
	// Test des constructeurs et de l'assignation
	Fixed a;
	Fixed const b(4.2f);
	Fixed const c(2);
	Fixed d(b);
	Fixed z(0);

	printB("Initial values:");
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "z: " << z << std::endl;
	pause();
	
	// Test des opérateurs de comparaison
	printB("\nComparison operators:");
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	pause();

	// Test des opérateurs arithmétiques
	printB("\nArithmetic operators:");
	Fixed result;
	result = b + c;
	std::cout << "b + c: " << result << std::endl;
	result = b - c;
	std::cout << "b - c: " << result << std::endl;
	result = b * c;
	std::cout << "b * c: " << result << std::endl;
	result = b / c;
	std::cout << "b / c: " << result << std::endl;
	std::cout << "b / z: " << std::flush;
	result = b / z;
	std::cout << std::endl;
	pause();

	// Test des opérateurs d'incrémentation et de décrémentation
	printB("\nIncrement/Decrement operators:");
	std::cout << "value of a: " << a << std::endl;
	std::cout << "After ++a: " << ++a << std::endl;
	std::cout << "After a++: " << a++ << std::endl;
	std::cout << "value of a: " << a << std::endl;
	std::cout << "After --a: " << --a << std::endl;
	std::cout << "After a--: " << a-- << std::endl;
	std::cout << "value of a: " << a << std::endl;
	pause();

	// Test des méthodes min et max
	printB("\nMin/Max functions:");
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
	pause();

	// Test des opérateurs avec des valeurs de float et d'int
	Fixed const e(42.42f);
	Fixed const f(10);
	
	printB("\nTests with different types:");
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "e + f: " << (e + f) << std::endl;
	std::cout << "e - f: " << (e - f) << std::endl;
	std::cout << "e * f: " << (e * f) << std::endl;
	std::cout << "e / f: " << (e / f) << std::endl;

	return 0;
}
