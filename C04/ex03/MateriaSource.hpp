#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource
{
public:
	MateriaSource();
	MateriaSource(std::string const & type);
	MateriaSource(const MateriaSource& other);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& other);
	
	// bool	const & isFree() const;
	// void	toggleMateriaAvailability();
	// void use(ICharacter& target);
	
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif

