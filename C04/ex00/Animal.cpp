#include "Animal.hpp"


Animal::Animal() : type("Animal") {

}

Animal::Animal(const Animal &other) {
(void)other;
}

Animal& Animal::operator=(const Animal& src) {
(void)src;
return (*this);
}

Animal::~Animal() {

}

void	Animal::makeSound() const {

}

const std::string	&Animal::getType() const {
	return (type);
}

void	Animal::print(std::string str)
{
	std::cout << str << std::endl;
}