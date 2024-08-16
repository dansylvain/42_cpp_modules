#ifndef DOG_HPP
#define DOG_HPP

#include "main.hpp"

class Dog : public AAnimal
{
	private:
		Brain* myBrain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog& src);
		~Dog(); 
		
		using AAnimal::getType;
		Brain*	getBrain() const;
		void	getGlobalKnowledge();
		void	makeSound() const;
};

#endif