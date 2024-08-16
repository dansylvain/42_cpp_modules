#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
void	print(std::string str);

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
		void	makeSound() const;
		const std::string&	getType() const;
};

#endif