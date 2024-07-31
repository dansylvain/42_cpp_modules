#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
	public:
	// constructors and destructor
	virtual ~ICharacter() {}
	
	// geters and seters
	virtual std::string const & getName() const = 0;
	
	// action member functions
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif