#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	printCreation();
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	if (this != &src)
		this->type = src.getType();
return (*this);
}

WrongAnimal::~WrongAnimal() {

}

void	WrongAnimal::makeSound() const {
	print(getType() + " says hi");
}

const std::string	&WrongAnimal::getType() const {
	return (type);
}

void	WrongAnimal::printCreation()
{
	print(getType() + " created");
}