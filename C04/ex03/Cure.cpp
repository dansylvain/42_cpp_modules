#include "Cure.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Cure::Cure() : AMateria()
{
	type = "cure";
	print("Cure created (default constructor)");
}

Cure::Cure(std::string const & type) : AMateria()
{
	Cure::type = type;
	print("Cure created (parameter constructor)");
}

Cure::Cure(const Cure& other) : AMateria()
{
	type = other.type;
	print("Cure created (copy constructor)");
}

Cure::~Cure()
{
	print("Cure destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		print("Cure copied");
		AMateria::operator=(other);
	}
	return (*this);
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
Cure* Cure::clone() const
{
	print("Cure cloned");
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	print("* heals " + target.getName() + "’s wounds *");
	(void)target;
}