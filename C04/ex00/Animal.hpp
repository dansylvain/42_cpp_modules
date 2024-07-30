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
		~Animal(); 

		// other member unctions
		void	makeSound() const;
		const std::string&	getType() const;
		void	printCreation();

};

#endif