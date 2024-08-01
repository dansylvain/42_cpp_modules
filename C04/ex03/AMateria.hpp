#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "main.h"

class ICharacter;

class AMateria
{
	protected:
		std::string 	*type;
		bool			*free;
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
		bool		const & isFree() const;
		void		toggleMateriaAvailability();

		// action member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif