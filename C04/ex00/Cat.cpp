#include "Cat.hpp"


Cat::Cat() : Animal() {
	type = "Cat";
	print("Cat created");
}

Cat::Cat(const Cat &other) : Animal(other){
	print("Cat created");
	type = other.getType();
}

Cat& Cat::operator=(const Cat& src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Cat::~Cat() {
	print("Cat destroyed");
}

void	Cat::makeSound() const {
	print(getType() + " says MEOW!");
}
