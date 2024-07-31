#include "Cure.hpp"

Cure::Cure() : AMateria(), type("cure")
{
}
Cure::Cure(std::string const & type) : AMateria(), type(type)
{
}
Cure::Cure(const Cure& other) : AMateria(), type(other.type)
{

}
Cure::~Cure()
{

}
Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}
Cure* Cure::clone() const
{
	return new Cure(*this);

}
void Cure::use(ICharacter& target)
{
	print("* heals <name>’s wounds *");
	(void)target;
}