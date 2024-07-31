#include "Cure.hpp"

Cure::Cure() : AMateria() {
	type = "cure";
}

Cure::Cure(std::string const & type) : AMateria() {
	(void)type;
}

Cure::Cure(const Cure &other) : AMateria() {
	(void)other;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
	{
		AMateria::operator=(other);
		this->type = other.type;
	}
	return (*this);
}

Cure::~Cure() {

}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	(void)target;
}

