#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : ICharacter
{
	protected:
		std::string name;
	public:
		Character();
		Character(std::string const & name);
		Character(const Character& other);
		~Character();
		Character& operator=(const Character& other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif