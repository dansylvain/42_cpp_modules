#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* myBrain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog& src);
		~Dog(); 
		
		using Animal::getType;
		Brain*	getBrain() const;
		void	getGlobalKnowledge();
		void	makeSound() const;
};

#endif