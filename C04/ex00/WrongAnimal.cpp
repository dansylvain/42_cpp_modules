#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal") {

}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
(void)other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
(void)src;
return (*this);
}

WrongAnimal::~WrongAnimal() {

}

void	WrongAnimal::makeSound() const {

}

const std::string	&WrongAnimal::getType() const {
	return (type);
}

void	WrongAnimal::print(std::string str)
{
	std::cout << str << std::endl;
}