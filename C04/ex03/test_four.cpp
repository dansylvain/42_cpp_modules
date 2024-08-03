#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void	print(std::string str);
void	printB(const std::string& str);
void	printF(std::string str);
void printFB(const std::string& str);
void	test_one();
void	test_two();
void	displayAppState(MateriaSource source);

void	displayAppState(MateriaSource *source)
{
	printF("Source state:");
	source->	displayMaterias();
	printF("AMAteria state:");
	AMateria::displayMaterias();
	printF("Characters state:");
	Character::characters[0]->displayMaterias();
}

void	test_four()
{
	print("Welcome to the jungle");
}