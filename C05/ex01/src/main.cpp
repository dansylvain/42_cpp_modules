#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"
#include "Form.hpp"

int main (void)
{
	print("Welcome to the jungle");
	print("");
	printB("--------- Bureaucrats Tests -------------");
	printB("\nCreate bureaucrats:");
	Bureaucrat bureaucrat;
	Bureaucrat *zaphod = new Bureaucrat("Zaphod Beeblebrox", 3	);
	printB("\ntest << operator:");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	printB("\ntest wrong level:");
	try
	{
		Bureaucrat bureaucrat("Kamel", 666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\nTest increment and decrement methods:");	
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
	printB("\nTest assignment operator:");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	bureaucrat = *zaphod;
	std::cout << bureaucrat << std::endl;
	pause();
	printB("\n--------- Forms Tests -------------");
	printB("\nCreate forms");
	Form form;
	Form *form42 = new Form("form42", 42, 142);

	printB("\ntest << operator:");
	std::cout << form << std::endl;
	std::cout << *form42 << std::endl;
	printB("\nTest wrong level");
	try
	{
		Form form7B("form7B", 151, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\nTest beSigned method:");
	std::cout << *form42 << std::endl;
	try
	{
		form42->beSigned(*zaphod);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *form42 << std::endl;
	printB("\n");

	std::cout << form << std::endl;
	form = *form42;
	Bureaucrat prostetnic("Prostetnic Vogon Jeltz", 74);
	std::cout << form << std::endl;
	print("");
	
	Form form7B("form7B", 42, 42);
	std::cout << form7B << std::endl;
	try
	{
		prostetnic.signForm(form7B);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << form7B << std::endl;
	
	print("");
	printB("--------- clean ressources --------");
	delete form42;
	delete zaphod;

}

