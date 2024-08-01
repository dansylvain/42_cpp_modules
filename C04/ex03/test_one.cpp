#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Ground.hpp"
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
	Character character1;
	Character character2("Pug");
	Cure copyCure(cure2);
	Ice copyIce(ice2);
	Character copyCharacter(character2);
	Character characTest("Saligaud");

	print("");
	printB("*****Initiazation tests ****************");
	print("type :" + cure.getType());
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
	if (TEST)
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
	character1.equip(&cure);
	character1.equip(&ice2);
	character1.equip(&iceTest);
	printB("char1 inventory before");
	if (TEST)
		character1.displayMaterias();
	print("");
	printB("char2 inventory before");
	if (TEST)
		character2.displayMaterias();
	character1 = character2;
	print("");
	printB("char1 inventory after");
	if (TEST)
		character1.displayMaterias();
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
	AMateria *ice_tmp = quelle->createMateria(ICE);
	AMateria *cure_tmp = quelle->createMateria(CURE);
	AMateria *nada_tmp = quelle->createMateria("NADAZERO");
	printB("Materia display");
	print(ice_tmp->getType());
	print(cure_tmp->getType());
	if (nada_tmp)
		print(nada_tmp->getType());
	print("");

	printB("********** Create Ground ***************");
	Ground* ground = new Ground;
	print("");
	printB("******* Test equip Ground **************");
	printB("charac inv");
	printB("equip materias");
	if (TEST)
		character1.displayMaterias();
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
	if (TEST)
		ground->displayMaterias();
	print("");
	printB("******** Test unequip Ground ***********");
	ground->unequip(4);
	ground->unequip(2);
	if (TEST)
		ground->displayMaterias();
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


	delete ice_tmp;
	delete cure_tmp;
	// delete nada_tmp;
	delete ice3;
	delete cure3;
	delete quelle;
	delete ground;
}