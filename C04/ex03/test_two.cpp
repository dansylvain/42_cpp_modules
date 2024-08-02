#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	print(std::string str);
void	printB(const std::string& str);
void	test_one();
void	test_two();

void	test_two()
{
	printB("*******Objects creation ********");
	print("");
	MateriaSource	source;
	Character		character[3];
	print("");

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
	
}
