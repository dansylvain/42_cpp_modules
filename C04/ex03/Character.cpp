#include "Character.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Character::Character() : ICharacter(), name("Bobby"), materiaNbr(0)
{
	initInv();
	print("Character created (default constructor)");
}

Character::Character(std::string const & name) : ICharacter(), name(name), materiaNbr(0)
{
	initInv();
	print("Character created (parameter constructor)");
}

Character::Character(const Character& other) : ICharacter(), name(other.name), materiaNbr(0)
{
	initInv();
	print("Character created (copy constructor)");
}

Character::~Character()
{
	print("Character destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		print("Character copied");
		ICharacter::operator=(other);
		name = other.name;
	}
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
std::string const & Character::getName() const
{
	return (name);
}

int	const & Character::getMateriaNbr() const
{
	// std::cout << materiaNbr << std::endl;
	return (materiaNbr);
}

void		Character::setMateriaNbr(int num)
{
	materiaNbr += num;
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void Character::equip(AMateria* m)
{
	if (getMateriaNbr() < 4)
	{
		inv[getMateriaNbr()] = m;
		setMateriaNbr(1);
	}
	(void)m;
}

void Character::unequip(int idx)
{
	if (inv[idx])
	{
		inv[idx] = NULL;
		setMateriaNbr(-1);
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (inv[idx] && idx < 4 && idx >= 0)
		inv[idx]->use(target);
}

void Character::displayMaterias()
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i])
			std::cout << i << ": " << inv[i]->getType() << std::endl;
	}
		// print(inv[i]->getType());
}

/**========================================================================
 *                           UTILS
 *========================================================================**/

void	Character::initInv()
{
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}
