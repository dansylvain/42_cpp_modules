#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "main.hpp"

class AAnimal
{
	protected:
		std::string type;

	public:
		// constructors and destructors
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal& operator=(const AAnimal& src);
		virtual ~AAnimal(); 

		// other member unctions
		virtual void	makeSound() const = 0;
		virtual const	std::string&	getType() const;
};

#endif