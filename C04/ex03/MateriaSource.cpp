#include "MateriaSource.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
MateriaSource::MateriaSource()
{
	initInv();
	print("MateriaSource Created (default constructor)");
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	initInv();
	(void)other;
}

MateriaSource::~MateriaSource()
{
	delete[] inv;
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

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void MateriaSource::learnMateria(AMateria *m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inv[i] == NULL && m->isFree())
		{
			inv[i] = m->clone();
			break;
		}
	}
	if (i == 4 && m->isFree())
		print("MateriaSource full");
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* ptr;
	if (type == ICE)
		ptr = new Ice();
	else if (type == CURE)
		ptr = new Cure();
	else ptr = NULL;
	return (ptr);
}

const std::string&	MateriaSource::getMateriaType(int idx)
{
	return (inv[idx]->getType());
}

/**========================================================================
 *                           UTILS
 *========================================================================**/

void	MateriaSource::initInv()
{
	inv = new AMateria*[4];
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
		// print(inv[i]->getType());
}