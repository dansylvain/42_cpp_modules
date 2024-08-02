#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"

void	print(std::string str);
void	printB(const std::string& str);
void	test_one();
void	test_two();
void	displayAppState(MateriaSource source);


void	test_two()
{
	printB("*******Objects creation ********");
	print("");
	MateriaSource	source;
	print("");
	
	AMateria *ice = AMateria::addMateria(new Ice);
	AMateria *cure = AMateria::addMateria(new Cure);
	ICharacter *bobby = ICharacter::createNewCharacter("BOBBY");
	ICharacter *charly = ICharacter::createNewCharacter("Charly");

	print(bobby->getName());
	bobby->equip(ice);	
	// bobby->equip(cure);	
	bobby->equip(ice);	
	bobby->equip(ice);	
	bobby->equip(ice);	
	bobby->displayMaterias();
	charly->equip(cure);
	charly->use(0, *bobby);
	AMateria *ice2 = cure->clone();
	AMateria *ice3 = cure->clone();
	AMateria *ice4 = cure->clone();
	AMateria *ice5 = cure->clone();
	AMateria *ice6 = cure->clone();
	AMateria *ice7 = ice->clone();
	AMateria *ice8 = ice->clone();
	AMateria *ice9 = ice->clone();
	AMateria *ice10 = ice->clone();

	print(ice2->getType());

	static_cast<Cure*>(ice2)->use(*bobby);
	ice->use(*charly);
	// bobby->equip(ice);	
	// charly->equip(cure);	
	// charly->equip(ice);	
	// charly->equip(cure);	
	// charly->equip(ice);	
	// charly->equip(ice);	
	
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	source.learnMateria(ice2);
	
	print("before: Source content:");
	source.displayMaterias();
	AMateria* materia = source.createMateria(ICE);
	print("after:  Source content:");
	source.displayMaterias();
	print(materia->getType());
	(void)ice;
	(void)cure;
	(void)charly;
	
	printB("** display all materias    *****");
	AMateria::displayMaterias();
	
	printB("**create materias - ground *****");
	
	printB("Ground content:");

	print("");
	printB("*******source learns materias *");
	
	printB("source content:");

	print("");
	printB("***** source creates materia ***");
	printB("source content:");
	printB("ground content:");
	print("");
	printB("********************************");
	print("");
	printB("********************************");
	print("");
	printB("********************************");
	print("");
	printB("********************************");
	print("");
	printB("********************************");
	print("");
	printB("********************************");
	print("");
	printB("*******Objects destruction *****");
	print("");

	printB("Materias on the ground: ");
	AMateria::displayMaterias();
	for (int i = 0; i < ICharacter::characterCount; i++)
	{
		printB("Character " + ICharacter::characters[i]->getName() + ": ");
		ICharacter::characters[i]->displayMaterias();
	}
	printB("Materia Source : ");
	source.displayMaterias();
	AMateria::cleanup();
	ICharacter::cleanup();

	(void)ice3;
	(void)ice4;
	(void)ice5;
	(void)ice6;
	(void)ice7;
	(void)ice8;
	(void)ice9;
	(void)ice10;

	
}
