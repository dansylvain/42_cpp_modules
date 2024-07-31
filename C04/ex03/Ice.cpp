#include "Ice.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Ice::Ice() : AMateria(), type("ice")
{
	print("Ice created (default constructor)");
}

Ice::Ice(std::string const & type) : AMateria(), type(type)
{
	print("Ice created (parameter constructor)");
}

Ice::Ice(const Ice& other) : AMateria(), type(other.type)
{
	print("Ice created (copy constructor)");
}

Ice::~Ice()
{
	print("ice destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		print("Ice copied");
		AMateria::operator=(other);
	}
	return (*this);
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
Ice* Ice::clone() const
{
	print("Ice clone");
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	print("* shoots an ice bolt at <name> *");
	(void)target;
}