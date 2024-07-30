#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		// constructors and destructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal& src);
		virtual ~WrongAnimal(); 

		// other member unctions
		virtual void	makeSound() const;
		const std::string&	getType() const;

		static void	print(std::string str);
};

#endif