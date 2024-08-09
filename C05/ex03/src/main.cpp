#include <iostream>
#include "Bureaucrat.hpp"
#include "main.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	RobotomyRequestForm order66("order66", "All jedis");
	PresidentialPardonForm form666("form666", "All humans");

	ShrubberyCreationForm *form42 = new ShrubberyCreationForm("form42", "ouioui");
	print("");
	std::cout << form << std::endl;
	std::cout << *form42 << std::endl;
	std::cout << order66 << std::endl;
	std::cout << form666 << std::endl;
	print("");
	
	try
	{
		zaphod->signForm(order66);
		zaphod->signForm(form666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << order66 << std::endl;
	std::cout << form666 << std::endl;
	
	print("");
	
	
	try
	{
		ShrubberyCreationForm form7B("form7B", "nonnon");
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
	
	ShrubberyCreationForm form7B("form7B", "what");
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
	print("--------- execution tests- --------");
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
	print("");
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
	
	
	print("");
	print("--------- Intern Tests ------------");
	Intern newIntern;
	AForm *newForm1;
	AForm *newForm2;
	AForm *newForm3;
	// AForm *newForm4;
	newForm1 = newIntern.makeForm("ShrubberyCreationForm", "FirstTarget");
	newForm2 = newIntern.makeForm("RobotomyRequestForm", "SecondTarget");
	newForm3 = newIntern.makeForm("PresidentialPardonForm", "ThirdPresidentialPardonFormTarget");
	// newForm4 = newIntern.makeForm("UnknownForm", "FourthTarget");
	try
	{
		newForm1->beSigned(*zaphod);
		newForm1->execute(*zaphod);
		print("");
		zaphod->signForm(*newForm2);
		zaphod->executeForm(*newForm2);
		print("");
		newForm3->beSigned(*zaphod);
		newForm3->execute(*zaphod);
		print("");
		// zaphod->signForm(*newForm4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	print("");
	print("--------- clean ressources --------");
	delete form42;
	delete zaphod;

}

void	print(std::string str)
{
	std::cout << str << std::endl;
}