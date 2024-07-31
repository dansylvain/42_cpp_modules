#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

void	print(std::string str);

class ICharacter;

class Ice : AMateria
{
	protected:
		std::string type;
	public:
		// constructors and destructor
		Ice();
		Ice(std::string const & type);
		Ice(const Ice& other);
		~Ice();

		// assignment operator
		Ice& operator=(const Ice& other);

		// geters and seters
		
		// action member functions
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif