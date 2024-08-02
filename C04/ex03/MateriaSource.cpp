#include "MateriaSource.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
MateriaSource::MateriaSource()
{
	print("MateriaSource Created (default constructor)");
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
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
			// Do something here?
			break;
		}
	}
	if (i == 4 && m->isFree())
		print("MateriaSource full");
}
void MateriaSource::createMateria(std::string const & type)
{
	(void)type;
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
	// inv = new AMateria*[4];
	// for (int i = 0; i < 4; i++)
	// 	inv[i] = NULL;
}

void	MateriaSource::displayMaterias() const
{
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (inv[i])
	// 		std::cout << i << ": " << inv[i]->getType() << std::endl;
	// }
		// print(inv[i]->getType());
}
