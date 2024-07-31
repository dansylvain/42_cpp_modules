#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
void	print(std::string str);
class AMateria;

class ICharacter
{
	ICharacter(std::string const & type);
	ICharacter(const ICharacter& other);
	ICharacter& operator=(const ICharacter& other);
	public:
	virtual ~ICharacter();
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif