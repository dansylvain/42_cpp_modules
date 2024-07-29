#include "Dog.hpp"


Dog::Dog() : Animal() {
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal() {
(void)other;
}

Dog& Dog::operator=(const Dog& src) {
(void)src;
return (*this);
}

Dog::~Dog() {

}

void	Dog::makeSound() const {
	print("Dog says hi");
}