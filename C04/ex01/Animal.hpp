#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
void	print(std::string str);

class Animal {
	protected:
		std::string type;
	public:
		// constructors and destructors
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal& src);
		virtual ~Animal(); 

		// other member unctions
		virtual void	makeSound() const;
		virtual const	std::string&	getType() const;
		virtual void	getGlobalKnowledge();

};

#endif