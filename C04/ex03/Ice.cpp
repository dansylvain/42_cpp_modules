#include "Ice.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Ice::Ice() : AMateria()
{
	*type = ICE;
	print("Ice created (default constructor)");
}

Ice::Ice(std::string const & type) : AMateria()
{
	*Ice::type = type;
	print("Ice created (parameter constructor)");
}

Ice::Ice(const Ice& other) : AMateria(other)
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
void Ice::clone() const
{
	print("Ice cloned");
	AMateria::addMateria(new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	print("* shoots an ice bolt at " + target.getName() + " *");
}