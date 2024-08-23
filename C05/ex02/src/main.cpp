#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{
	printB("\n--------- Bureaucrats Tests -------------");
	printB("\nCreate Bureaucrats:");
	Bureaucrat bureaucrat;
	Bureaucrat *zaphod = new Bureaucrat("Zaphod Beeblebrox", 3	);
	Bureaucrat lowLewelBureaucrat;
	Bureaucrat prostetnic("Prostetnic Vogon Jeltz", 150);

	printB("\nTest << operator");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	printB("\nTest wrong level");
	try
	{
		Bureaucrat bureaucrat("Kamel", 666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\nTest increment and decrement methods");
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
	printB("\nTest assignment operator");
	std::cout << bureaucrat << std::endl;
	std::cout << *zaphod << std::endl;
	bureaucrat = *zaphod;
	std::cout << bureaucrat << std::endl;
	pause();
	printB("\n--------- Forms Tests -------------");
	printB("\nCreate forms");
	ShrubberyCreationForm form;
	RobotomyRequestForm order66("order66", "All jedis");
	PresidentialPardonForm form666("form666", "All humans");
	ShrubberyCreationForm *form42 = new ShrubberyCreationForm("form42", "ouioui");
	ShrubberyCreationForm form7B("form7B", "what");

	printB("\ntest assignment operator");
	std::cout << form << std::endl;
	std::cout << *form42 << std::endl;
	std::cout << order66 << std::endl;
	std::cout << form666 << std::endl;
	
	printB("\nTest signForm method");
	try
	{
		zaphod->signForm(order66);
		zaphod->signForm(form666);
		lowLewelBureaucrat.signForm(form666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << order66 << std::endl;
	std::cout << form666 << std::endl;
	
	printB("\nTest temp form creation");
	try
	{
		ShrubberyCreationForm form7B("form7B", "nonnon");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\nTest beSigned method");
	std::cout << *form42 << std::endl;
	try
	{
		form42->beSigned(*zaphod);
		form42->beSigned(lowLewelBureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << *form42 << std::endl;
	print("");

	printB("\nTest assignment operator");
	std::cout << form << std::endl;
	form = *form42;
	std::cout << form << std::endl;
	
	printB("\nTest signForm method");
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
	pause();
	printB("\n--------- execution tests- --------");
	printB("\nTest execute method");
	try
	{
		form42->execute(*zaphod);
		form.execute(*zaphod);
		order66.execute(*zaphod);
		form666.execute(*zaphod);
		form7B.execute(*zaphod);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printB("\nTest executeForm method");
	try
	{
		zaphod->executeForm(*form42);
		zaphod->executeForm(form);
		zaphod->executeForm(order66);
		zaphod->executeForm(form666);
		zaphod->executeForm(form7B);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	pause();
	printB("\n--------- clean ressources --------");
	delete form42;
	delete zaphod;

}
