#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"

int main (void)
{
	print("Welcome to the jungle");
	Bureaucrat bureaucrat;
	Bureaucrat *zaphod = new Bureaucrat("Zaphod Beeblebrox", 3	);
	print("");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	print("");
	try
	{
		zaphod->incrementGrade();
		zaphod->incrementGrade();
		zaphod->incrementGrade();
		zaphod->incrementGrade();
		bureaucrat.incrementGrade();
		bureaucrat.incrementGrade();
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	delete zaphod;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}