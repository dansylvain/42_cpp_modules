#include "AMateria.hpp"
#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
MateriaSource::MateriaSource()
{
	print("MateriaSource Created (default constructor)");
}

// MateriaSource::MateriaSource(std::string const & type)
// {
// 	print("MateriaSource Created (parameter constructor)");
// }

MateriaSource::MateriaSource(const MateriaSource& other)
{
	if (this != &other)
	{
		print("MateriaSource Created (copy constructor)");
		// do something?
	}
	(void)other;
}

MateriaSource::~MateriaSource()
{
	print("MateriaSource destroyed");
}


/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		print("MateriaSource copied");
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *ptr)
{
	(void)ptr;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* ptr;
	type == "ice" ? ptr = new Ice() : ptr = new Cure();
	return (ptr);
}
