#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Ground.hpp"

void	print(std::string str);
void	printB(const std::string& str);
void	test_one();
void	test_two();

void	test_two()
{
	printB("*******Objects creation ********");
	print("");
	Ground			ground;
	MateriaSource	source;
	Character		character[3];
	print("");

	printB("**create materias - ground *****");
	ground.equip(new Ice);
	ground.equip(new Cure);
	printB("Ground content:");
	ground.displayMaterias();

	print("");
	printB("*******source learns materias *");
	source.learnMateria(ground.inv[0]);
	source.learnMateria(ground.inv[1]);
	printB("source content:");
	source.displayMaterias();

	print("");
	printB("***** source creates materia ***");
	ground.equip(source.createMateria(source.getMateriaType(0)));
	ground.equip(source.createMateria(source.getMateriaType(0)));
	ground.equip(source.createMateria(source.getMateriaType(0)));
	ground.equip(source.createMateria(source.getMateriaType(0)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	ground.equip(source.createMateria(source.getMateriaType(1)));
	printB("source content:");
	source.displayMaterias();
	printB("ground content:");
	ground.displayMaterias();
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
