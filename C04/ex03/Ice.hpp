#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"

class Ice : public AMateria
{
		private:
		int	id;
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
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif