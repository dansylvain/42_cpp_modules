#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"

class Cure : public AMateria
{
	private:
		int			*id;
		std::string *loc;
	public:
		// constructors and destructor
		Cure();
		Cure(std::string const & type);
		Cure(const Cure& other);
		~Cure();

		// assignment operator
		Cure& operator=(const Cure& other);
		
		// getter
		using AMateria::getType;

		// action member functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif