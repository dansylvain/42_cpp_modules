#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource
{
	private:
		static AMateria*		inv[4];
	public:
		// constructors and destructor
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		// assignment operator
		MateriaSource& operator=(const MateriaSource& other);

		// getters and setters
		static	AMateria	**getInv();

		// action methods
		virtual void 		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);

		// utils methods
		void				initInv();
		static void			displayMaterias();
		static void			displayMateriaCount();
};

#endif

