#include "Dog.hpp"


Dog::Dog() : Animal() {
	type = "Dog";
	print("Dog created - with a brain");
	myBrain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog created - with a brain" << std::endl;
	type = other.getType();
	myBrain = new Brain();
}

Dog& Dog::operator=(const Dog& src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Dog::~Dog() {
	print("Dog destroyed");
	delete myBrain;
}

void	Dog::makeSound() const {
	print(getType() + " says WOOF!");
}
