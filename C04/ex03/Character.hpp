#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
	public:
		static Character*		characters[100];
		static int				characterCount;
		std::string 	*name;
		AMateria* 		inv[4];
		Character();
		Character(const Character& other);

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
		// geters and seters
		
		// action member functions
		static	Character*	createNewCharacter(const std:: string &name);

		static	void		cleanup();
		// Utils
		//tmp

};

#endif