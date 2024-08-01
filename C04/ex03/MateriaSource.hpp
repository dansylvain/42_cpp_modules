#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource
{
	private:
		AMateria** 		inv;
	public:
		MateriaSource();
		MateriaSource(std::string const & type);
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);
		
		// bool	const & isFree() const;
		// void	toggleMateriaAvailability();
		// void use(ICharacter& target);
		
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		void	initInv();
		void	displayMaterias() const;
};

#endif

