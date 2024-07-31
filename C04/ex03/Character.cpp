#include "Character.hpp"


Character::~Character()
{
	
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