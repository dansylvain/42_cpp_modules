#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		std::string 	*name;
		AMateria* 		inv[4];
		Character();
		Character(const Character& other);

	public:
		// constructors and destructor
		Character(std::string const & name);
		~Character();

		// assignment operator
		Character& operator=(const Character& other);

		// geters and seters
		std::string const & getName() const;

		// action member functions
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void	initInv();
		void displayMaterias();

		// Utils
		//tmp

};

#endif