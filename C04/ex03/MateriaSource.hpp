#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource
{
	private:
	public:
		static AMateria*		inv[4];
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		virtual void 		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
		void				initInv();
		static void				displayMaterias();
		static void		displayMateriaCount();

};

#endif

