#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* myBrain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& src);
		~Cat(); 
		
		Brain *getBrain() const;
		virtual void	makeSound() const;	
		void	getGlobalKnowledge();
};

#endif