#include "MateriaSource.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
MateriaSource::MateriaSource()
{
	print("MateriaSource Created (default constructor)");
	initInv();
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	(void)other;
	initInv();
}

MateriaSource::~MateriaSource()
{
	print("MateriaSource destroyed");
	initInv();
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

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void MateriaSource::learnMateria(AMateria *m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inv[i] == NULL)
		{
			print(m->getType() + " added to inv");
			m->setLoc(MATERIASOURCE);
			inv[i] = m;
			break;
		}
	}
	if (i == 4)
		print("MateriaSource full");
	(void)m;
}
AMateria *MateriaSource::createMateria(std::string const & type)
{
	AMateria *ptr;
	if (type == CURE)
		ptr = AMateria::addMateria(new Cure(type));
	else if (type == ICE)
	{
		std::cout << "ICE CREATED" << std::endl;
		ptr = AMateria::addMateria(new Ice(type));
	}
	return (ptr);
}

/**========================================================================
 *                           UTILS
 *========================================================================**/

void	MateriaSource::initInv()
{
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

void	MateriaSource::displayMaterias() const
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i])
			std::cout << i << ": " << inv[i]->getType() << std::endl;
	}
}
