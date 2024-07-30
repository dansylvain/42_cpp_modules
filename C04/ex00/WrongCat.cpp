#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	printCreation();
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(){
	type = other.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

WrongCat::~WrongCat() {

}
