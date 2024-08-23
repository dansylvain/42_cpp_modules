#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"

int main (void)
{
	printB("\n************ create bureaucrats ******************");

	Bureaucrat bureaucrat;
	Bureaucrat *zaphod = new Bureaucrat("Zaphod Beeblebrox", 3	);
	
	printB("\n************ Test << operator ********************");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;

	printB("\n************ Test Wrong Level ********************");
	try
	{
		Bureaucrat bureaucrat("Kamel", 666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\n***** Test increment and decrement methods *******");
	try
	{
		zaphod->incrementGrade();
		zaphod->incrementGrade();
		zaphod->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		bureaucrat.incrementGrade();
		bureaucrat.decrementGrade();
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\n*********** Test assignment operator  ************");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	bureaucrat = *zaphod;
	std::cout << bureaucrat << std::endl;
	printB("\n************ destroy bureaucrats *****************");

	delete zaphod;
}