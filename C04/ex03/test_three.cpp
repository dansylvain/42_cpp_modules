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
	print("");
	printB("******* Initial data creation *************");
	MateriaSource *source = new MateriaSource;
	Character *clitorine = Character::createNewCharacter("Clitorine");
	Character *capucin = Character::createNewCharacter("Capucin");
	print("");
	printB("******** AMateria addMateria1 *************");
	Ice *ice = static_cast<Ice*>(AMateria::addMateria("ice"));
	AMateria::addMateria("cure");
	print(ice->getType());
	print("");
	printB("******** AMateria addMateria2 *************");
	Cure *cure = static_cast<Cure*>(AMateria::addMateria(new Cure));
	
	print("");
	printB("******** AMateria getType *****************");
	print(cure->getType());
	print(ice->getType());
	
	print("");
	printB("******** AMateria setLoc ******************");
	print("before: " + cure->getLoc());
	cure->setLoc(MATERIASOURCE);
	print("after: " + cure->getLoc());
	cure->setLoc(GROUND);
	print("after: " + cure->getLoc());
	
	
	
	print("");
	printB("******** AMateria clone *******************");
	
	
	print("");
	printB("******** AMateria displayMaterias *********");
	
	
	print("");
	printB("******** AMateria use *********************");
	cure->use(*clitorine);
	ice->use(*capucin);
	
	print("");
	printB("********* Character equip *****************");
	clitorine->equip(cure);
	
	print("");
	printB("********* Character unequip ***************");
	
	print("");
	printB("******** AMateria getLoc ******************");
	print(cure->getLoc());
	print(ice->getLoc());
	
	print("");
	printB("********* Character getName ***************");
	
	
	print("");
	printB("********* Character use *******************");
	
	
	print("");
	printB("********* Character createNewCharacter ****");
	
	
	print("");
	printB("********* Character displayMaterias *******");
	
	
	print("");
	printB("********** Cure/Ice clone *****************");
	
	
	print("");
	printB("********** Cure/Ice use *******************");
	
	
	print("");
	printB("********** MateriaSource learnMateria *****");
	
	
	print("");
	printB("******* MateriaSource createMateria *******");
	



	
	Character::cleanup();
	AMateria::cleanup();
	delete source;
}