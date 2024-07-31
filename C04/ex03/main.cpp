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
	Character character1;
	Character character2("Pug");
	Cure copyCure(cure2);
	Ice copyIce(ice2);
	Character copyCharacter(character2);

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
	print("****************************************");
	print("");
	print("****************************************");
	print("");
	print("****************************************");
	print("");
	print("****************************************");
	print("");
	print("****************************************");

	return 0;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}



