#include "WrongCat.hpp"


WrongCat::WrongCat() : Animal() {
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : Animal() {
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