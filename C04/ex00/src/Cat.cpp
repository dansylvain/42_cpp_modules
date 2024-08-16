#include "Cat.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Cat::Cat() : Animal()
{
	type = "Cat";
	print("Cat created");
}

Cat::Cat(const Cat &other) : Animal(other)
{
	print("Cat created");
	type = other.getType();
}

Cat::~Cat()
{
	print("Cat destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Cat& Cat::operator=(const Cat& src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
void	Cat::makeSound() const
{
	print(" says MEOW!");
}
