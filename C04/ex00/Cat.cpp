#include "Cat.hpp"


Cat::Cat() : Animal() {
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal() {
(void)other;
}

Cat& Cat::operator=(const Cat& src) {
(void)src;
return (*this);
}

Cat::~Cat() {

}

void	Cat::makeSound() const{
	print("Cat says hi");
}