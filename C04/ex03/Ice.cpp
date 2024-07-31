#include "Ice.hpp"

Ice::Ice() : AMateria(), type("ice")
{
}
Ice::Ice(std::string const & type) : AMateria(), type(type)
{
}
Ice::Ice(const Ice& other) : AMateria(), type(other.type)
{

}
Ice::~Ice()
{

}
Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}
Ice* Ice::clone() const
{
	return new Ice(*this);

}
void Ice::use(ICharacter& target)
{
	print("* shoots an ice bolt at <name> *");
	(void)target;
}