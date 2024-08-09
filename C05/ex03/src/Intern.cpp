#include "Intern.hpp"
#include "main.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTORS
 *========================================================================**/
Intern::Intern()
{
	print("Intern created (default constructor)");
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
	print("Intern created (copy constructor)");
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	print("Intern destroyed");
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
FormType Intern::getFormType(const std::string formName) const
{
	if (formName == "ShrubberyCreationForm")
		return (SHRUBBERY);
	if (formName == "RobotomyRequestForm")
		return (ROBOTOMY);
	if (formName == "PresidentialPardonForm")
		return (PRESIDENTIAL);
	return (UNKNOWN);
	
}

AForm* Intern::makeForm(const std::string formName, std::string formTarget) const
{
	AForm* ptr;

	FormType formType = getFormType(formName);
	switch (formType)
	{
		case SHRUBBERY:
			ptr = new ShrubberyCreationForm("ShrubberyCreationForm", formTarget);
			break;
		case ROBOTOMY:
			ptr = new RobotomyRequestForm("RobotomyRequestForm", formTarget);
			break;
		case PRESIDENTIAL:
			ptr = new PresidentialPardonForm("PresidentialPardonForm", formTarget);
			break;
		default:
			std::cout << "Form " << formName << " doesn't exist and can't be created." << std::endl;
			ptr = NULL;
			return ptr;
	}
	std::cout << "Intern creates " << formName << std::endl;
	return ptr;
}