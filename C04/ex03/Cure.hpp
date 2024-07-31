#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

void	print(std::string str);

class ICharacter;

class Cure : AMateria
{
	protected:
		std::string type;
	public:
		// constructors and destructor
		Cure();
		Cure(std::string const & type);
		Cure(const Cure& other);
		~Cure();

		// assignment operator
		Cure& operator=(const Cure& other);
		
		// action member functions
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif