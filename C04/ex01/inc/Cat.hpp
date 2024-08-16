#ifndef CAT_HPP
#define CAT_HPP

#include "main.hpp"
class Cat : public Animal
{
	private:
		Brain* myBrain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& src);
		~Cat(); 

		void	makeSound() const;	
		
		using Animal::getType;
		Brain* getBrain() const;
		void	getGlobalKnowledge();
};

#endif