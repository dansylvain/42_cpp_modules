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
		
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		void	initInv();
		void	displayMaterias() const;
};

#endif

