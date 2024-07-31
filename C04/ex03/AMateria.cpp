#include "AMateria.hpp"
#include <iostream>

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
AMateria::AMateria()
{
	print("AMateria Created (default constructor)");
}

AMateria::AMateria(std::string const & type) : type(type)
{
	print("AMateria Created (parameter constructor)");
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	print("AMateria Created (copy constructor)");
}

AMateria::~AMateria()
{
	print("AMateria destroyed");
}


/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

/**========================================================================
 *                           GETERS AND SETERS
 *========================================================================**/
std::string const & AMateria::getType() const
{
	return (type);
}

/**========================================================================
 *                       ACTION MEMBER FUNCTIONS
 *========================================================================**/
void AMateria::use(ICharacter& target)
{
	(void)target; //! this function needs to be redefined in derived classes
}
