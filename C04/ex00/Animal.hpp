#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		void	makeSound();
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal& src);
		~Animal(); 
};

#endif