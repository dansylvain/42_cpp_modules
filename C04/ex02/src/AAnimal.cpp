#include "main.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
AAnimal::AAnimal() : type("AAnimal")
{
	print("AAnimal created");
}

AAnimal::AAnimal(const AAnimal &other)
{
	print("AAnimal created");
	type = other.getType();
}

AAnimal::~AAnimal()
{
	print("AAnimal destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
AAnimal& AAnimal::operator=(const AAnimal& src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS>
 *========================================================================**/
const std::string	&AAnimal::getType() const
{
	return (type);
}

/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
void	AAnimal::makeSound() const
{
	print(getType() + " says hi");
}