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

	print(ice2->getType());

	static_cast<Cure*>(ice2)->use(*bobby);
	ice->use(*charly);
	// bobby->equip(ice);	
	// charly->equip(cure);	
	// charly->equip(ice);	
	// charly->equip(cure);	
	// charly->equip(ice);	
	// charly->equip(ice);	
	
	
	(void)ice;
	(void)cure;
	(void)charly;
	
	
	
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
	AMateria::cleanup();
	ICharacter::cleanup();
}
