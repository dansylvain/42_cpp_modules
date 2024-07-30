#include "Cat.hpp"


Cat::Cat() : Animal() {
	type = "Cat";
	print("Cat created - with a brain");
	myBrain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other){
	myBrain = new Brain();
	type = other.getType();
	print("Cat created - with a brain");
}

Cat& Cat::operator=(const Cat& src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Cat::~Cat() {
	print("Cat destroyed");
	delete myBrain;
}

void	Cat::makeSound() const {
	print(getType() + " says MEOW!");
}
