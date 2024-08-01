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

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void Ground::equip(AMateria* m)
{
	for (int i = 0; i < MAXMATERIA; i++)
	{
		if (inv[i] == NULL && m->isFree())
		{
			inv[i] = m;
			m->toggleMateriaAvailability();
			break;
		}
	}
}

void Ground::unequip(int idx)
{
	if (inv[idx])
	{
		inv[idx]->toggleMateriaAvailability();
		inv[idx] = NULL;
	}
}
/**========================================================================
 *                           UTILS
 *========================================================================**/
void	Ground::initInv()
{
	inv = new AMateria*[MAXMATERIA];
	for (int i = 0; i < MAXMATERIA; i++)
		inv[i] = NULL;
}

void	Ground::displayMaterias() const
{
	for (int i = 0; i < MAXMATERIA; i++)
	{
		if (inv[i])
			std::cout << i << ": " << inv[i]->getType() << std::endl;
	}
		// print(inv[i]->getType());
}