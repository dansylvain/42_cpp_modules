#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		static Character*	characters[100];
		static int			characterCount;
		std::string 		*name;
		AMateria* 			inv[4];
	public:
		// constructors and destructor
		Character();
		Character(const Character& other);
		Character(std::string const & name);
		~Character();

		// assignment operator
		Character&			operator=(const Character& other);

		// geters and seters
		std::string const & getName() const;
		static Character	**getCharacters();
		static int			getCharacterCount();
		AMateria			**getInv();
		
		// action 
		void 				equip(AMateria* m);
		void				equip(int idx);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		
		// utils
		static	Character*	createNewCharacter(const std:: string &name);
		void				initInv();
		void				displayMaterias();
		void				displayMateriaCount();
		static	void		cleanup();
};

#endif