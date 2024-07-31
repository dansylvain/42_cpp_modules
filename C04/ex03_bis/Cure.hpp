#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : AMateria {
	public:
	Cure();
	// constructeur par défaut
	Cure(std::string const & type);
	// constructeur par copie
	Cure(const Cure &other);
	// operateur d'assignation
	Cure& operator=(const Cure& other);
	// destructeur
	~Cure();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif