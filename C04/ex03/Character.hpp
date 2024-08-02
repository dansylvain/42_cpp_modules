#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		std::string 	*name;
		AMateria** 		inv;

	public:
		// constructors and destructor
		Character();
		Character(std::string const & name);
		Character(const Character& other);
		~Character();

		// assignment operator
		Character& operator=(const Character& other);

		// geters and seters
		std::string const & getName() const;

		// action member functions
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		// Utils
		void	initInv();
		//tmp
		void displayMaterias();

};

#endif