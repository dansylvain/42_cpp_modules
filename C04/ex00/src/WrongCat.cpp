#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	print("WrongCat created");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	print("WrongCat created");
	type = other.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

WrongCat::~WrongCat()
{
	print("WrongCat destroyed");
}

void	WrongCat::makeSound() const
{
	print(" says WOEM!");
}
