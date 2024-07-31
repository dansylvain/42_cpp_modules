#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

void	print(std::string str);

class ICharacter;

class Cure : public AMateria
{
	private:
		Cure*	ptr;
	public:
		// constructors and destructor
		Cure();
		Cure(std::string const & type);
		Cure(const Cure& other);
		~Cure();

		// assignment operator
		Cure& operator=(const Cure& other);
		
		// geters and seters
		// std::string const & getType() const;
		using AMateria::getType;

		// action member functions
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif