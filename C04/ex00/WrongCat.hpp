#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		void	makeSound() const;
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat& operator=(const WrongCat& src);
		~WrongCat(); 	
};

#endif