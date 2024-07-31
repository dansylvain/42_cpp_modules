#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

void	print(std::string str);

class ICharacter;

class Ice : public AMateria
{
		private:
		Ice*	ptr;
	public:
		// constructors and destructor
		Ice();
		Ice(std::string const & type);
		Ice(const Ice& other);
		~Ice();

		// assignment operator
		Ice& operator=(const Ice& other);

		// geters and seters
		using AMateria::getType;
		
		// action member functions
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif