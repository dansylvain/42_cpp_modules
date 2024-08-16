#ifndef CAT_HPP
#define CAT_HPP

#include "main.hpp"

class Cat : public AAnimal
{
	private:
		Brain* myBrain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& src);
		~Cat(); 

		using AAnimal::getType;
		Brain*	getBrain() const;
		void	getGlobalKnowledge();
		void	makeSound() const;	
};

#endif