#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
		// constructors and destructor
		virtual ~ICharacter() {}
		static ICharacter*		characters[100];
		static int				characterCount;
		// geters and seters
		virtual std::string const & getName() const = 0;
		
		// action member functions
		virtual void		equip(AMateria* m) = 0;
		virtual void		unequip(int idx) = 0;
		virtual void		use(int idx, ICharacter& target) = 0;
		static	ICharacter*	createNewCharacter(const std:: string &name);
		virtual void		displayMaterias() = 0;

		static	void		cleanup();

};

#endif