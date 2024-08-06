#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog& src);
		~Dog(); 
		using Animal::getType;

		virtual void	makeSound() const;

};

#endif