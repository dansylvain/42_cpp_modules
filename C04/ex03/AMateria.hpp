#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "main.h"

class ICharacter;

class AMateria
{
	protected:
		std::string 	*type;
		AMateria(const AMateria& other);
		std::string		loc;

	public:
		static int		materiaCount;
		static AMateria *materias[100];
		AMateria(std::string const & type);
		// constructors and destructor
		AMateria();
		virtual ~AMateria();

		// assignment operator
		AMateria& operator=(const AMateria& other);

		// geters and seters
		std::string const & getType() const;
		std::string const & getLoc() const;
		void setLoc(std::string newLoc);
		static	int	getGroundSize();

		// action member functions
		static	AMateria*	addMateria(AMateria *newMateria);
		static	AMateria*	addMateria(std::string type);
		static	void		cleanup();
		virtual void		use(ICharacter& target);
		virtual AMateria*		clone() const = 0;
		static void	displayMaterias();
		static void	displayMateriaCount();


};

#endif