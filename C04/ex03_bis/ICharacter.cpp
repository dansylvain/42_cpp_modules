#include "ICharacter.hpp"

// constructeur par défaut
ICharacter::ICharacter(std::string const & type) {
	print("ICharacter Created");
	(void)type;
};

// constructeur par copie
ICharacter::ICharacter(const ICharacter& other) {
	// TODO logic to be implemented
	print("ICharacter Created");
	(void)other;
	
}
// operateur d'assignation
ICharacter& ICharacter::operator=(const ICharacter& other) {
	// TODO logic to be implemented
	(void)other;
	return (*this);
}

// destructeur
ICharacter::~ICharacter() {
	print("ICharacter destroyed");
}

