#include "Intern.hpp"
#include "main.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTORS
 *========================================================================**/
Intern::Intern()
{
	print("Intern created (default constructor)");
}

Intern::Intern(const Intern& intern)
{
	print("Intern created (copy constructor)");
}

Intern& Intern::operator=(const Intern& other)
{
	return (*this);
}

Intern::~Intern()
{
	print("Intern destroyed");
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
AForm* Intern::makeForm() const
{
	//! do something
}