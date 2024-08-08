#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"
#include "Form.hpp"

int main (void)
{
	print("Welcome to the jungle");
	print("");
	print("--------- Bureaucrats Tests -------------");

	Bureaucrat bureaucrat;
	Bureaucrat *zaphod = new Bureaucrat("Zaphod Beeblebrox", 3	);
	print("");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	print("");
	try
	{
		Bureaucrat bureaucrat("Kamel", 666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");
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
	print("");
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
	print("");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	bureaucrat = *zaphod;
	std::cout << bureaucrat << std::endl;

	print("");
	print("--------- Forms Tests -------------");






	Form form;
	Form *Form42 = new Form("Form42", 42, 142);
	print("");
	std::cout << form << std::endl;
	std::cout << *Form42 << std::endl;
	print("");
	try
	{
		Form form7B("form7B", 151, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");
	std::cout << *Form42 << std::endl;
	std::cout << form << std::endl;
	form = *Form42;
	std::cout << form << std::endl;



	delete Form42;
	delete zaphod;

}

void	print(std::string str)
{
	std::cout << str << std::endl;
}