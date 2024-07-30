#include "Animal.hpp"


Animal::Animal() : type("Animal") {
	printCreation();
}

Animal::Animal(const Animal &other) {
	type = other.getType();
}

Animal& Animal::operator=(const Animal& src) {
	if (this != &src)
		this->type = src.getType();
return (*this);
}

Animal::~Animal() {

}

void	Animal::makeSound() const {
	print(getType() + " says hi");
}

const std::string	&Animal::getType() const {
	return (type);
}

void	Animal::printCreation()
{
	print(getType() + " created");
}