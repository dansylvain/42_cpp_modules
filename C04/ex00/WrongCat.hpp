#ifndef WRONG_CAT
#define WRONG_CAT

#include "Animal.hpp"

class WrongCat : public Animal {
	public:
		void	makeSound();
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat& operator=(const WrongCat& src);
		~WrongCat(); 
};

#endif