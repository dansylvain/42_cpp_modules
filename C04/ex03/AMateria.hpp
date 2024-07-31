#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

void	print(std::string str);

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		// constructors and destructor
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		~AMateria();

		// assignment operator
		AMateria& operator=(const AMateria& other);

		// geters and seters
		std::string const & getType() const;
		
		// action member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif