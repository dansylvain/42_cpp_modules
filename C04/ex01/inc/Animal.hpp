#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "main.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		// constructors and destructors
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal& src);
		virtual ~Animal(); 

		// other member unctions
		virtual void	makeSound() const;
		virtual const	std::string&	getType() const;
		virtual void	getGlobalKnowledge();

};

#endif