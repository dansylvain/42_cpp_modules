#include "Cat.hpp"


Cat::Cat() : Animal() {
	type = "Cat";
	printCreation();
}

Cat::Cat(const Cat &other) : Animal(){
	type = other.getType();
}

Cat& Cat::operator=(const Cat& src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Cat::~Cat() {

}
