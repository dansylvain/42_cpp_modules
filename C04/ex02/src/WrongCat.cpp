#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	print("WrongCat created - with a brain");
	myBrain = new Brain();
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	print("WrongAnimal created - with a brain");
	myBrain = new Brain();
	type = other.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

WrongCat::~WrongCat() {
	print("WrongCat destroyed");
	delete myBrain;
}

void	WrongCat::makeSound() const {
	print(getType() + " says MEOW!");
}
