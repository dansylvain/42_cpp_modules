#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"

class Cure : public AMateria
{
	private:
		int	id;
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
		void clone() const;
		void use(ICharacter& target);
};

#endif