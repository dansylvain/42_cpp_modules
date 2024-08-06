#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& src);
		~Cat(); 
		Brain* myBrain;

		virtual void	makeSound() const;	
		void	getGlobalKnowledge();
};

#endif