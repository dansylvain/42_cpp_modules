#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
AMateria::AMateria() : type("turlututu"), free(new bool(true))
{
	print("AMateria Created (default constructor)");
}

AMateria::AMateria(std::string const & type) : type(type), free(new bool(true))
{
	print("AMateria Created (parameter constructor)");
}

AMateria::AMateria(const AMateria& other) : type(other.type), free(new bool(true))
{
	print("AMateria Created (copy constructor)");
}

AMateria::~AMateria()
{
	delete free;
	print("AMateria destroyed");
}


/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		print("AMateria copied");
		type = other.type;
	}
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
std::string const & AMateria::getType() const
{
	return (type);
}

bool	const & AMateria::isFree() const
{
	return (*free);
}

void	AMateria::toggleMateriaAvailability()
{
	std::cout << "before: " << *free;
	*free ? *free = 0 : *free = 1;
	std::cout << ", after: " << *free <<std::endl;
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void AMateria::use(ICharacter& target)
{
	(void)target;
}
