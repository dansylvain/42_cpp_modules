#include "Dog.hpp"


Dog::Dog() : Animal() {
	type = "Dog";
	printCreation();
}

Dog::Dog(const Dog &other) : Animal() {
	type = other.getType();
}

Dog& Dog::operator=(const Dog& src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Dog::~Dog() {

}
