#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource
{
	private:
		AMateria** 		inv;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);
		const std::string&	getMateriaType(int idx);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		void	initInv();
		void	displayMaterias() const;
};

#endif

