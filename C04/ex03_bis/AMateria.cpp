#include "AMateria.hpp"

// constructeur par défaut
AMateria::AMateria() {
	print("AMateria Created");
}

AMateria::AMateria(std::string const & type) {
	print("AMateria Created");
	(void)type;
};

// constructeur par copie
AMateria::AMateria(const AMateria& other) {
	// TODO logic to be implemented
	(void)other;
	print("AMateria Created");
}
// operateur d'assignation
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// destructeur
AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	// TODO logic to be implemented
	return type;
};

void AMateria::use(ICharacter& target) {
	// TODO logic to be implemented
	(void)target;
};