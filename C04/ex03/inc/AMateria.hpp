#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "main.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string 	*type;
		std::string		loc;
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
		std::string const & getLoc() const;
		void 				setLoc(std::string newLoc);
		static	int			getGroundSize();
		static	AMateria	**getMaterias();
		static	int			getMateriaCount();
		
		// action
		virtual void		use(ICharacter& target);
		virtual AMateria*		clone() const = 0;

		// utils
		static	AMateria*	addMateria(AMateria *newMateria);
		static	AMateria*	addMateria(std::string type);
		static	void		cleanup();
		static	void		displayMateriaCount();
		static	void		displayMaterias();
};

#endif