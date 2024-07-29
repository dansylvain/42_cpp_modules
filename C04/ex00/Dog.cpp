#include "Dog.hpp"


Dog::Dog() : Animal() {

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

void	Dog::makeSound() {

}