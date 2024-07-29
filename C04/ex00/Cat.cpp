#include "Cat.hpp"


Cat::Cat() : Animal() {

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

void	Cat::makeSound() {

}