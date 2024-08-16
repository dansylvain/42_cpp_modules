#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	print("WrongAnimal created");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	print("WrongAnimal created");
	type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	if (this != &src)
		this->type = src.getType();
return (*this);
}

WrongAnimal::~WrongAnimal() {
	print("WrongAnimal destroyed");
}

void	WrongAnimal::makeSound() const {
	print(" says ih");
}

const std::string	&WrongAnimal::getType() const {
	return (type);
}
