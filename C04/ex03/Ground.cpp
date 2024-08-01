#include "Ground.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Ground::Ground()
{
	initInv();
	print("Ground Created (default constructor)");
}

Ground::Ground(const Ground& other)
{
	initInv();
	(void)other;
}

Ground::~Ground()
{
	delete[] inv;
	print("Ground destroyed");
}


/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Ground& Ground::operator=(const Ground& other)
{
	if (this != &other)
	{
		print("Ground copied");
	}
	return (*this);
}

void Ground::learnMateria(AMateria *m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inv[i] == NULL && m->isFree())
		{
			inv[i] = m;
			m->toggleMateriaAvailability();
			break;
		}
	}
	// std::cout << i << std::endl;
	if (i == 4 && m->isFree())
		print("Ground full");
}
AMateria* Ground::createMateria(std::string const & type)
{
	AMateria* ptr;
	if (type == ICE)
		ptr = new Ice();
	else if (type == CURE)
		ptr = new Cure();
	else ptr = NULL;
	return (ptr);
}

/**========================================================================
 *                           UTILS
 *========================================================================**/

void	Ground::initInv()
{
	inv = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

void	Ground::displayMaterias() const
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i])
			std::cout << i << ": " << inv[i]->getType() << std::endl;
	}
		// print(inv[i]->getType());
}