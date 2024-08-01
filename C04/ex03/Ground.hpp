#ifndef GROUND_HPP
#define GROUND_HPP

#include "Ice.hpp"
#include "Cure.hpp"

class Ground
{
	private:
		AMateria** 		inv;
	public:
		Ground();
		Ground(const Ground& other);
		virtual ~Ground();

		Ground& operator=(const Ground& other);
		
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		void	initInv();
		void	displayMaterias() const;
};

#endif

