#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "main.h"
void	print(std::string str);
void	printB(const std::string& str);
void	test_one();


void	test_one()
{
	TEST =false;
	printB("Welcome to the Jungle");
	print("");
	printB("********* CREATION TEST ****************");
	Cure cure;
	Cure cure2("cureeee");
	Ice ice("tristesse");
	Ice ice2;
	Ice iceTest("Fanta");
	Cure cureTest("CocaCola");
	Character character2("Pug");
	Cure copyCure(cure2);
	Ice copyIce(ice2);
	Character characTest("Saligaud");

	print("");
	printB("*****Initiazation tests ****************");
	print("type :" + cure.getType());
	print("type :" + cure2.getType());
	print("type :" + ice.getType());
	print("type :" + ice2.getType());
	print("type :" + character2.getName());
	print("");
	printB("Copy tests:");
	print("type :" + copyCure.getType());
	print("type :" + copyIce.getType());
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

	printB("********* Use method tests *************");
	ice.use(character2);
	print("");

	printB("********** clone test ******************");
	
	print("");
	printB("********** inv tests********************");
	character2.equip(&ice);
	character2.equip(&iceTest);
	character2.equip(&cureTest);
	character2.equip(&cure2);
	character2.equip(&cure2);
	if (TEST)
		character2.displayMaterias();
	character2.equip(&cure2);
	print("");
	
	printB("********** use func test ***************");
	character2.use(2, character2);
	character2.use(-2, characTest);
	character2.use(16, characTest);
	character2.use(1, characTest);	
	print("");

	printB("****** unequip tests *******************");
	printB("inv before unsetting:");
	if (TEST)
		character2.displayMaterias();
	character2.unequip(1);
	character2.unequip(3);
	print("");
	printB("inv after unequip:");
	if (TEST)
		character2.displayMaterias();
	print("");
	printB("inv after reequipping:");
	character2.equip(&iceTest);
	character2.equip(&ice);
	if (TEST)
		character2.displayMaterias();
	print("");
	printB("inv after unequipping everything:");
	character2.unequip(0);
	character2.unequip(1);
	character2.unequip(2);
	character2.unequip(3);
	if (TEST)
		character2.displayMaterias();
	// print("");

	printB("***Charac Copy contructor tests ********");
	printB("char1 inventory before");
	
	print("");
	printB("char2 inventory before");
	if (TEST)
		character2.displayMaterias();
	print("");
	printB("char1 inventory after");
	print("");
	printB("char2 inventory after");
	if (TEST)
		character2.displayMaterias();
	print("");

	printB("******** isfree materia bool test ******");
	printB("before equipping");
	if (TEST)
		character2.displayMaterias();
	// character2.equip(&cureTest);
	// character2.equip(&ice);
	// print("");
	// printB("after equipping");
	if (TEST)
		character2.displayMaterias();
	// print("");
	// printB("****** cerate MateriaSource ************");
	MateriaSource *quelle = new MateriaSource;
	// (void)quelle;
	// character2.unequip(0);
	// character2.unequip(1);
	// print("");
	
	printB("******* learn MateriaSource ************");
	quelle->learnMateria(&iceTest);
	quelle->learnMateria(&cureTest);
	quelle->learnMateria(&iceTest);
	quelle->learnMateria(&iceTest);
	quelle->learnMateria(&ice2);
	quelle->learnMateria(&cure2);
	if (TEST)
		quelle->displayMaterias();
	quelle->learnMateria(&ice);
	quelle->learnMateria(&ice);
	quelle->learnMateria(&ice);
	quelle->learnMateria(&ice);

	print("");
	printB("******** create Materias tests *********");
	printB("Materais creation");
	printB("Materia display");
	print("");

	printB("********** Create Ground ***************");
	print("");
	printB("******* Test equip Ground **************");
	printB("charac inv");
	printB("equip materias");
	print(cureTest.getType());
	// std::cout << *cureTest.type << *cureTest.free << std::endl;
	// Cure tmp1;
	// Cure tmp2;
	// Ice tmp3;
	// Cure tmp4;
	// Ice tmp5;
	// printB("equip materias");
	// ground->equip(ice_tmp);
	// ground->equip(cure_tmp);
	// ground->equip(&cure2);
	// ground->equip(cure3);
	// ground->equip(&cure);
	// ground->equip(&cureTest);
	// ground->equip(ice3);
	// ground->equip(&ice);
	// ground->equip(&iceTest);
	// ground->equip(&tmp1);
	// ground->equip(&tmp2);
	// ground->equip(&tmp3);
	// ground->equip(&tmp4);
	// ground->equip(&tmp5);

	printB("display ground materias:");
	print("");
	printB("****************************************");
	print("");
	printB("****************************************");
	print("");
	printB("****************************************");
	print("");
	printB("****************************************");
	print("");
	printB("****** destroy classes *****************");


	// delete nada_tmp;

	delete quelle;
}