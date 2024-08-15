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
void	printFB(const std::string& str);

void	test_three()
{
	TEST = true;
	print("");
	printB("******* Initial data creation *************");
	MateriaSource *source = new MateriaSource;
	
	print("");
	myPause();
	printB("********* Character createNewCharacter ****");
	Character *clitorine = Character::createNewCharacter("Clitorine");
	Character *constantin = Character::createNewCharacter("Constantin");
	
	
	print("");
	myPause();
	printB("******** AMateria addMateria1 *************");
	AMateria::addMateria("ice");
	AMateria::addMateria("ice");
	AMateria::addMateria("ice");
	AMateria::addMateria("ice");
	AMateria::addMateria("cure");
	AMateria::addMateria("cure");
	AMateria::addMateria("cure");
	AMateria::addMateria("cure");
	Ice *ice = static_cast<Ice*>(AMateria::addMateria("ice"));
	Ice *ice2 = static_cast<Ice*>(AMateria::addMateria("ice"));
	Ice *ice3 = static_cast<Ice*>(AMateria::addMateria("ice"));
	Ice *ice4 = static_cast<Ice*>(AMateria::addMateria("ice"));
	Ice *ice5 = static_cast<Ice*>(AMateria::addMateria("ice"));
	AMateria::addMateria("cure");
	print(ice->getType());
	print("");
	myPause();
	printB("******** AMateria addMateria2 *************");
	Cure *cure = static_cast<Cure*>(AMateria::addMateria(new Cure));
	
	print("");
	myPause();
	printB("******** AMateria getType *****************");
	print(cure->getType());
	print(ice->getType());
	
	print("");
	myPause();
	printB("******** AMateria setLoc ******************");
	print("before: " + cure->getLoc());
	cure->setLoc(MATERIASOURCE);
	print("after: " + cure->getLoc());
	cure->setLoc(GROUND);
	print("after: " + cure->getLoc());
	
	print("");
	myPause();
	printB("******** AMateria clone *******************");
	AMateria *tmp = cure->clone();
	print(tmp->getType());	
	
	print("");
	myPause();
	printB("******** AMateria use *********************");
	cure->use(*clitorine);
	ice->use(*constantin);
	
	print("");
	myPause();
	printB("********* Character equip *****************");
	print("Charc inv before use");
	clitorine->displayMaterias();
	print("");
	clitorine->equip(ice);
	clitorine->equip(ice2);
	clitorine->equip(ice3);
	clitorine->equip(ice4);
	clitorine->equip(ice5);
	print("Charc after before use");
	clitorine->displayMaterias();
	print("");

	
	print("");
	myPause();
	printB("********* Character unequip ***************");
	print("Charc inv before unequip");
	clitorine->displayMaterias();
	print("");

	clitorine->unequip(0);
	clitorine->unequip(3);
	print("Charc inv after unequip");
	clitorine->displayMaterias();
	print("");

	print("");
	myPause();
	printB("******** AMateria getLoc ******************");
	print(cure->getLoc());
	print(ice->getLoc());
	
	print("");
	myPause();
	printB("********* Character getName ***************");
	print(constantin->getName());
	print(clitorine->getName());
	
	print("");
	myPause();
	printB("********* Character use *******************");
	constantin->equip(tmp);
	constantin->use(0, *clitorine);
	clitorine->use(1, *constantin);
	
	print("");
	myPause();
	printB("********* Character displayMaterias *******");
	print(constantin->getName() + "inv: ");
	constantin->displayMaterias();
	print("");
	print(clitorine->getName() + "inv: ");
	clitorine->displayMaterias();
	print("");
	print("");
	myPause();
	printB("********** Cure/Ice clone *****************");
	cure->clone();


	print("");
	myPause();
	printB("********** Cure/Ice use *******************");
	ice->use(*clitorine);
	cure->use(*constantin);
	
	
	print("");
	myPause();
	printB("********** MateriaSource learnMateria *****");
	source->learnMateria(cure);
	source->learnMateria(cure);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	printB("Source inv:");
	source->displayMaterias();
	print("");
	
	print("");
	myPause();
	printB("******* MateriaSource createMateria *******");
	source->createMateria(CURE);

	print("");

	myPause();
	printB("******* ressources destruction ************");
	


	Character::cleanup();
	AMateria::cleanup();
	delete source;
}