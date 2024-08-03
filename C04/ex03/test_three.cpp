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

void	displayAppState(MateriaSource *source)
{
	printF("Source state:");
	source->	displayMaterias();
	printF("AMAteria state:");
	AMateria::displayMaterias();
	printF("Characters state:");
	Character::characters[0]->displayMaterias();
}

void	test_three()
{
	print("");
	printB("******* Initial data creation *************");
	MateriaSource *source = new MateriaSource;
	
	
	print("");
	printB("********* Character createNewCharacter ****");
	Character *clitorine = Character::createNewCharacter("Clitorine");
	Character *constantin = Character::createNewCharacter("Constantin");
	
	
	print("");
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
	AMateria *tmp = cure->clone();
	print(tmp->getType());	
	
	print("");
	printB("******** AMateria use *********************");
	cure->use(*clitorine);
	ice->use(*constantin);
	
	print("");
	printB("********* Character equip *****************");
	print("Charc inv before use");
	clitorine->displayMaterias();
	clitorine->equip(ice);
	clitorine->equip(ice2);
	clitorine->equip(ice3);
	clitorine->equip(ice4);
	clitorine->equip(ice5);
	print("Charc after before use");
	clitorine->displayMaterias();
	
	print("");
	printB("********* Character unequip ***************");
	print("Charc inv before unequip");
	clitorine->displayMaterias();
	clitorine->unequip(0);
	clitorine->unequip(3);
	print("Charc inv after unequip");
	clitorine->displayMaterias();

	print("");
	printB("******** AMateria getLoc ******************");
	print(cure->getLoc());
	print(ice->getLoc());
	
	print("");
	printB("********* Character getName ***************");
	print(constantin->getName());
	print(clitorine->getName());
	
	print("");
	printB("********* Character use *******************");
	constantin->equip(tmp);
	constantin->use(0, *clitorine);
	clitorine->use(1, *constantin);
	
	print("");
	printB("********* Character displayMaterias *******");
	print(constantin->getName() + "inv: ");
	constantin->displayMaterias();
	print(clitorine->getName() + "inv: ");
	clitorine->displayMaterias();
	print("");
	printB("********** Cure/Ice clone *****************");
	cure->clone();


	print("");
	printB("********** Cure/Ice use *******************");
	ice->use(*clitorine);
	cure->use(*constantin);
	
	
	print("");
	printB("********** MateriaSource learnMateria *****");
	// source->learnMateria(cure);
	// source->learnMateria(cure);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	printB("Source inv:");
	// source->displayMaterias();
	
	print("");
	printB("******* MateriaSource createMateria *******");
	source->createMateria(CURE);

	print("");

	displayAppState(source);

	printB("******* ressources destruction ************");
	


	Character::cleanup();
	AMateria::cleanup();
	delete source;
}