#include "Dog.hpp"


Dog::Dog() : Animal() {
	type = "Dog";
	print("Dog created");
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog created" << std::endl;
	type = other.getType();
}

Dog& Dog::operator=(const Dog& src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Dog::~Dog() {
	print("Dog destroyed");
}

void	Dog::makeSound() const {
	print(getType() + " says WOOF!");
}
