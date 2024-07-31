#include "Character.hpp"


Character::Character() : ICharacter()
{

}

Character::Character(std::string const & name) : ICharacter(), name(name)
{

}

Character::Character(const Character& other) : ICharacter(), name(other.name)
{

}

Character::~Character()
{

}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		ICharacter::operator=(other);
		name = other.name;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}
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