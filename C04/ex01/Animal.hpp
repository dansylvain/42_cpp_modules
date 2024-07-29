#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

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
		const std::string&	getType() const;

		static void	print(std::string str);
};

#endif