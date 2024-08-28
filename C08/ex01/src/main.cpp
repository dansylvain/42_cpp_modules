#include "main.hpp"
#include "Span.hpp"

int main()
{
	std::cout << "Welcome to the jungle" << std::endl;
	Span newSpan(5);

	try
	{
		newSpan.addNumber(40);
		newSpan.addNumber(47);
		newSpan.addNumber(553);
		newSpan.addNumber(42);
		newSpan.addNumber(49);
		newSpan.addNumber(10);
		newSpan.addNumber(2);
		newSpan.addNumber(-42);
		newSpan.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "minSpan :" << newSpan.shortestSpan() << std::endl;
	
	return (0);
}