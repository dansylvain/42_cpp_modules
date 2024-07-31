#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	print(std::string str);

int main()
{
	print("Welcome to the Jungle");
	print("");
	print("********* CREATION TEST ****************");
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
	print("*****Initiazation tests ****************");
	print("type :" + cure.getType());
	print("type :" + cure2.getType());
	print("type :" + ice.getType());
	print("type :" + ice2.getType());
	print("type :" + character1.getName());
	print("type :" + character2.getName());
	print("");
	print("Copy tests:");
	print("type :" + copyCure.getType());
	print("type :" + copyIce.getType());
	print("type :" + copyCharacter.getName());

	print("");
	print("*** assignment operator tests **********");
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
	print("********* Use method tests *************");
	cure2.use(character1);
	ice.use(character2);
	print("");
	print("********** clone test ******************");
	Ice *ice3 = ice2.clone();
	print((*ice3).getType());
	Cure *cure3 = cure2.clone();
	print((*cure3).getType());
	
	print("");
	print("********** inv tests********************");
	character2.equip(&ice);
	character2.equip(&iceTest);
	character2.equip(&cureTest);
	character2.equip(&cure2);
	character2.equip(&cure2);
	character2.displayMaterias();
	character2.equip(&cure2);
	print("");
	print("********** use func test ***************");
	character2.use(2, character2);
	character2.use(-2, characTest);
	character2.use(16, characTest);
	character1.use(2, characTest);
	character2.use(1, characTest);	
	print("");

	print("****** unequip tests *******************");
	print("inv before unsetting:");
	character2.displayMaterias();
	character2.unequip(1);
	character2.unequip(3);
	print("inv after unequip:");
	character2.displayMaterias();
	print("inv after reequipping:");
	character2.equip(&iceTest);
	character2.equip(&ice);
	character2.displayMaterias();
	print("inv after unequipping everything:");
	character2.unequip(0);
	// character2.unequip(1);
	// character2.unequip(2);
	character2.unequip(3);
	character2.displayMaterias();

	print("");
	print("***Charac Copy contructor tests ********");
	character1.equip(&cure);
	character1.equip(&ice2);
	character1.equip(&iceTest);
	print("char1 inventory before");
	character1.displayMaterias();
	print("char2 inventory before");
	character2.displayMaterias();
	character1 = character2;
	print("char1 inventory after");
	character1.displayMaterias();
	print("char2 inventory after");
	character2.displayMaterias();

	print("");
	print("");
	print("****************************************");
	print("");
	print("****************************************");
	print("");
	print("****** destroy classes *****************");
	delete ice3;
	delete cure3;

	return 0;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}



