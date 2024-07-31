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
	print("****************************************");
	print("********* CREATION TEST ****************");
	Cure cure;
	Cure cure2("cure");
	// Ice ice();
	Ice ice("tristesse");
	Ice ice2;
	Character character1;
	Character character2("Pug");
	print("");

	print("*****Initiazation tests ****************");
	print("type :" + cure2.getType());
	print("type :" + ice.getType());
	
	print("****************************************");
	print("****************************************");
	print("****************************************");
	print("****************************************");
	print("****************************************");

	return 0;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}



