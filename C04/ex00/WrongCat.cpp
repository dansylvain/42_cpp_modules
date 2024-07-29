#include "WrongCat.hpp"


WrongCat::WrongCat() : Animal() {

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

}