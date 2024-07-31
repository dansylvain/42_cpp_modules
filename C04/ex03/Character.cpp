#include "Character.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Character::Character() : ICharacter(), name("Bobby")
{
	print("Character created (default constructor)");
}

Character::Character(std::string const & name) : ICharacter(), name(name)
{
	print("Character created (parameter constructor)");
}

Character::Character(const Character& other) : ICharacter(), name(other.name)
{
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

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void Character::equip(AMateria* m)
{
	(void)m;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
}