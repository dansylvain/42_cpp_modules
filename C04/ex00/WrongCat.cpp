#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal() {
(void)other;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
(void)src;
return (*this);
}

WrongCat::~WrongCat() {

}

void	WrongCat::makeSound() const{
	print("WrongCat says hi");
}