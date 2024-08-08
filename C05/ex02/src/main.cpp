#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	// bureaucrat = *zaphod;
	std::cout << bureaucrat << std::endl;
	print("");
	print("--------- Forms Tests -------------");

	ShrubberyCreationForm form;
	ShrubberyCreationForm *form42 = new ShrubberyCreationForm("form42");
	print("");
	std::cout << form << std::endl;
	std::cout << *form42 << std::endl;
	print("");
	try
	{
		ShrubberyCreationForm form7B("form7B");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");
	std::cout << *form42 << std::endl;
	try
	{
		form42->beSigned(*zaphod);
		form42->beSigned(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *form42 << std::endl;
	print("");

	std::cout << form << std::endl;
	form = *form42;
	Bureaucrat prostetnic("Prostetnic Vogon Jeltz", 150);
	std::cout << form << std::endl;
	print("");
	
	ShrubberyCreationForm form7B("form7B");
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
	print("--------- clean ressources --------");
	delete form42;
	delete zaphod;

}

void	print(std::string str)
{
	std::cout << str << std::endl;
}