#ifndef DOG_HPP
#define DOG_HPP

#include "main.hpp"

class Dog : public Animal
{
	private:
		Brain* myBrain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog& src);
		~Dog(); 

		void	makeSound() const;
		
		using Animal::getType;
		Brain* getBrain() const;
		void	getGlobalKnowledge();
};

#endif