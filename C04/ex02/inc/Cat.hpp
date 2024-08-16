#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* myBrain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& src);
		~Cat(); 

		using Animal::getType;
		Brain*	getBrain() const;
		void	getGlobalKnowledge();
		void	makeSound() const;	
};

#endif