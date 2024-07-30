#include "Animal.hpp"


Animal::Animal() : type("Animal") {
	print("Animal created");
}

Animal::Animal(const Animal &other) {
	print("Animal created");
	type = other.getType();
}

Animal& Animal::operator=(const Animal& src) {
	if (this != &src)
		this->type = src.getType();
return (*this);
}

Animal::~Animal() {
	print("Animal destroyed");
}

void	Animal::makeSound() const {
	print(getType() + " says hi");
}

const std::string	&Animal::getType() const {
	return (type);
}

