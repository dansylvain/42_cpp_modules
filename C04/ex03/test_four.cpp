#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Terminal.hpp"

/**========================================================================
 *                             COMMENT BLOCK
 * 
 *  Always instantiate new Characters with Character::createNewCharacter()
 *  + call Character::cleanup
 * 
 *  Always instantiate new Materias with AMateria::addMateria("ice");
 *  + call AMateria::cleanup
 * 
 * the source you instantiate, you delete.
 *  
 *========================================================================**/
void	print(std::string str);
void	printB(const std::string& str);
void	printF(std::string str);
void printFB(const std::string& str);
void	test_one();
void	test_two();

void	displayAppState();

void	test_four()
{
	MateriaSource *source = new MateriaSource;

	AMateria *ice = AMateria::addMateria("ice");
	AMateria *cure = AMateria::addMateria("cure");
	
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(ice);
	source->learnMateria(cure);
	source->learnMateria(cure);
	source->learnMateria(cure);


	
	source->createMateria(ICE);
	source->createMateria(ICE);
	source->createMateria(ICE);
	source->createMateria(ICE);
	source->createMateria(ICE);
	source->createMateria(CURE);
	source->createMateria(CURE);
	source->createMateria(CURE);
	source->createMateria(CURE);

	
	Character *clitorine = Character::createNewCharacter("Clitorine");
	Character *constantin = Character::createNewCharacter("Constantin");
	
	clitorine->equip(ice);
	clitorine->equip(cure);
	clitorine->equip(cure);
	clitorine->equip(cure);
	clitorine->equip(6);
	clitorine->equip(7);
	clitorine->equip(3);
	clitorine->equip(3);
	clitorine->equip(3);
	clitorine->equip(3);
	constantin->equip(5);
	constantin->equip(8);
	constantin->equip(4);
	constantin->use(1, *clitorine);

	displayAppState();


	Character::cleanup();
	AMateria::cleanup();
	delete source;
}