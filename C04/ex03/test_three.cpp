#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void	print(std::string str);
void	printB(const std::string& str);
void	printF(std::string str);
void printFB(const std::string& str);
void	test_one();
void	test_two();
void	displayAppState(MateriaSource source);


void	test_three()
{
	printB("*******Objects creation ********");
	print("");
	MateriaSource	source;
	AMateria *ice = AMateria::addMateria(new Ice);
	AMateria *cure = AMateria::addMateria(new Cure);
	AMateria *ice2 = cure->clone();
	AMateria* materia = source.createMateria(ICE);

	

	// bobby->equip(cure);	
	
	

	print(ice2->getType());

	
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	
	source.displayMaterias();
	source.displayMaterias();
	print(materia->getType());
	(void)ice;
	(void)cure;
	

	AMateria::cleanup();
	Character::cleanup();


}