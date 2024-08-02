#include "Character.hpp"

/**========================================================================
 *                             COMMENT BLOCK
 *  
 *  ? delete[] to free 
 *  
 *  
 *========================================================================**/
/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Character::Character() : ICharacter()
{
	print("Character created (default constructor)");
	initInv();
}

Character::Character(std::string const & name) : ICharacter(), name(new std::string(name))
{
	print("Character created (parameter constructor)");
	initInv();
}

Character::Character(const Character& other) : ICharacter(), name(new std::string(*other.name))
{
	print("Character created (copy constructor)");
	initInv();
}

Character::~Character()
{
	delete name;
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
		*name = *other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inv[i])
				inv[i] = NULL;
			if (other.inv[i])
				inv[i] = other.inv[i];
		}
	}
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
std::string const & Character::getName() const
{
	return (*name);
}


/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] == NULL && m->getLoc() != getName())
		{
			inv[i] = m;
			m->setLoc(getName());
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (inv[idx])
	{
		inv[idx]->setLoc(GROUND);
		inv[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && inv[idx])
		inv[idx]->use(target);
}

void Character::displayMaterias()
{
	
	for (int i = 0; i < 4; i++)
	{
		if (inv[i])
			std::cout << i << ": " << inv[i]->getType() << std::endl;
	}
}

/**========================================================================
 *                           UTILS
 *========================================================================**/

void	Character::initInv()
{
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}
