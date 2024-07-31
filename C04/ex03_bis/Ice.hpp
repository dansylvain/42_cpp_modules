#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : AMateria {
	public:
	Ice();
	// constructeur par défaut
	Ice(std::string const & type);
	// constructeur par copie
	Ice(const Ice &other);
	// operateur d'assignation
	Ice& operator=(const Ice& other);
	// destructeur
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif