#include "Dog.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Dog::Dog() : Animal()
{
	type = "Dog";
	print("Dog created");
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog created" << std::endl;
	type = other.getType();
}

Dog::~Dog() {
	print("Dog destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Dog& Dog::operator=(const Dog& src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
void	Dog::makeSound() const
{
	print(" says WOOF!");
}
