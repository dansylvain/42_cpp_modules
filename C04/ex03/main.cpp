#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	print(std::string str);
void	printB(const std::string& str);

int main()
{
	printB("Welcome to the Jungle");
	print("");
	printB("********* CREATION TEST ****************");
	Cure cure;
	Cure cure2("cureeee");
	// Ice ice();
	Ice ice("tristesse");
	Ice ice2;
	Ice iceTest("Fanta");
	Cure cureTest("CocaCola");
	Character character1;
	Character character2("Pug");
	Cure copyCure(cure2);
	Ice copyIce(ice2);
	Character copyCharacter(character2);
	Character characTest("Saligaud");

	print("");
	printB("*****Initiazation tests ****************");
	// print("type :" + cure.getType());
	print("type :" + cure2.getType());
	print("type :" + ice.getType());
	print("type :" + ice2.getType());
	print("type :" + character1.getName());
	print("type :" + character2.getName());
	print("");
	printB("Copy tests:");
	print("type :" + copyCure.getType());
	print("type :" + copyIce.getType());
	print("type :" + copyCharacter.getName());
	print("");

	printB("*** assignment operator tests **********");
	print("type before:" + cure.getType());
	cure = cure2;
	print("type after:"  + cure.getType());
	print("");
	print("type before:" + ice.getType());
	ice = ice2;
	print("type after:"  + ice.getType());print("");
	print("");	
	print("type before:" + character1.getName());
	character1 = character2;
	print("type after:"  + character1.getName());print("");

	printB("********* Use method tests *************");
	cure2.use(character1);
	ice.use(character2);
	print("");

	printB("********** clone test ******************");
	Ice *ice3 = ice2.clone();
	print((*ice3).getType());
	print("");
	Cure *cure3 = cure2.clone();
	print((*cure3).getType());
	
	print("");
	printB("********** inv tests********************");
	character2.equip(&ice);
	character2.equip(&iceTest);
	character2.equip(&cureTest);
	character2.equip(&cure2);
	character2.equip(&cure2);
	character2.displayMaterias();
	character2.equip(&cure2);
	print("");
	
	printB("********** use func test ***************");
	character2.use(2, character2);
	character2.use(-2, characTest);
	character2.use(16, characTest);
	character1.use(2, characTest);
	character2.use(1, characTest);	
	print("");

	printB("****** unequip tests *******************");
	printB("inv before unsetting:");
	character2.displayMaterias();
	character2.unequip(1);
	character2.unequip(3);
	print("");
	printB("inv after unequip:");
	character2.displayMaterias();
	print("");
	printB("inv after reequipping:");
	character2.equip(&iceTest);
	character2.equip(&ice);
	character2.displayMaterias();
	print("");
	printB("inv after unequipping everything:");
	character2.unequip(0);
	character2.unequip(1);
	character2.unequip(2);
	character2.unequip(3);
	character2.displayMaterias();
	print("");

	printB("***Charac Copy contructor tests ********");
	character1.equip(&cure);
	character1.equip(&ice2);
	character1.equip(&iceTest);
	printB("char1 inventory before");
	character1.displayMaterias();
	print("");
	printB("char2 inventory before");
	character2.displayMaterias();
	character1 = character2;
	print("");
	printB("char1 inventory after");
	character1.displayMaterias();
	print("");
	printB("char2 inventory after");
	character2.displayMaterias();
	print("");

	printB("******** isfree materia bool test ******");
	printB("before equipping");
	character2.displayMaterias();
	character2.equip(&cureTest);
	character2.equip(&ice);
	print("");
	printB("after equipping");
	character2.displayMaterias();
	print("");
	printB("****** cerate MateriaSource ************");
	MateriaSource *quelle = new MateriaSource;
	(void)quelle;
	character2.unequip(0);
	character2.unequip(1);
	print("");
	
	printB("****** cerate MateriaSource ************");
	quelle->learnMateria(&iceTest);
	quelle->learnMateria(&cureTest);
	quelle->learnMateria(&iceTest);
	quelle->learnMateria(&iceTest);
	quelle->learnMateria(&ice2);
	quelle->learnMateria(&cure2);
	quelle->displayMaterias();
	quelle->learnMateria(&ice);
	quelle->learnMateria(&ice);
	quelle->learnMateria(&ice);
	quelle->learnMateria(&ice);

	print("");
	printB("****************************************");
	print("");
	printB("****** destroy classes *****************");

	delete ice3;
	delete cure3;
	delete quelle;
	return 0;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void printB(const std::string& str)
{
    // Code d'échappement pour le texte en gras (1) et couleur verte (32)
    std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}

