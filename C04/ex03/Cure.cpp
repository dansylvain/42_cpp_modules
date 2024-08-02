#include "Cure.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Cure::Cure() : AMateria(), id(new int(AMateria::materiaCount)), loc(new std::string("ground"))
{
	*type = CURE;
	print("Cure created (default constructor)");
}

Cure::Cure(std::string const & type) : AMateria(), id(new int(AMateria::materiaCount)), loc(new std::string("ground"))
{
	*Cure::type = type;
	print("Cure created (parameter constructor)");
}

Cure::Cure(const Cure& other) : AMateria(other), id(new int(AMateria::materiaCount)), loc(new std::string("ground"))
{
	print("Cure created (copy constructor)");
}

Cure::~Cure()
{
	delete id;
	delete loc;
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
AMateria* Cure::clone() const
{
	AMateria* ptr = new Cure(*this);
	AMateria::addMateria(ptr);
	print("Cure cloned");
	return (ptr);
}

void Cure::use(ICharacter& target)
{
	print("* heals " + target.getName() + "’s wounds *");
	(void)target;
}