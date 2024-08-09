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
	FormType formType = getFormType(formName);
	switch (formType)
	{
		case SHRUBBERY:
			return new ShrubberyCreationForm("ShrubberyCreationForm", formTarget);
		case ROBOTOMY:
			return new RobotomyRequestForm("RobotomyRequestForm", formTarget);
		case PRESIDENTIAL:
			return new PresidentialPardonForm("PresidentialPardonForm", formTarget);
		default:
			std::cout << "Form " << formName << " doesn't exist and can't be created." << std::endl;
			return NULL;
	}
}