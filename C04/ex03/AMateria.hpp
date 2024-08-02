#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "main.h"

class ICharacter;

class AMateria
{
	protected:
		std::string 	*type;
		bool			*free;
		static AMateria *materias[100];
		static int		materiaCount;
	public:


		// constructors and destructor
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		virtual ~AMateria();

		// assignment operator
		AMateria& operator=(const AMateria& other);

		// geters and seters
		std::string const & getType() const;

		// action member functions
		virtual void	clone() const = 0;
		virtual void	use(ICharacter& target);
		static	void	addMateria(AMateria *newMateria);
		static	void	cleanup();
};

#endif