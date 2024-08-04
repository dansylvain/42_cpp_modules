#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Terminal.hpp"	
#include <sstream>
#include <string>
#include <cstdlib> 
#include "unistd.h"

void	print(std::string str);
void	printB(const std::string& str);
void printFB(const std::string& str);

void	printF(std::string str);
void	test_one();
void	test_two();
void	test_three();
void	test_four();

bool isDigitsOnly(const std::string& str);
Character *getCharacterByName(std::string name);
AMateria *getMateriaFromCharInv(std::string index, Character *character);
AMateria *getMateriaToCreateByIndex(std::string index, MateriaSource *source);
AMateria *getMateriaFromGround(std::string index);


void	displayAppState()
{
	Terminal::framingFuncOutput(AMateria::materiaCount * 3, "Ground:", AMateria::displayMaterias, AMateria::displayMateriaCount);
	Terminal::framingFuncOutput(12, "Source:", MateriaSource::displayMaterias, MateriaSource::displayMateriaCount);
	for (int i = 0; i < Character::characterCount; i++)
	{
		if (Character::characters[i])
			Terminal::framingFuncOutput(12, Character::characters[i]->getName(), Character::characters[i]->displayMaterias, Character::characters[i]->displayMateriaCount);
	}
}
int main()
{

	std::string userInput;
	Terminal term;
	Character::createNewCharacter("Dan");
	MateriaSource *source = new MateriaSource;
	source->createMateria(ICE);
	source->createMateria(CURE);
	source->createMateria(CURE);
	source->createMateria(ICE);
	source->createMateria(ICE);
	source->createMateria(CURE);
	Character::characters[0]->equip(AMateria::materias[0]);
	source->learnMateria(AMateria::materias[0]);

	while (1)
	{
		term.execSystemCmd(term.clearCommand);
		displayAppState();
		term.displayString(term.contentMenu);
		term.displayString(term.mssg);
		std::getline(std::cin, userInput);
		std::istringstream iss(userInput);
		std::string token;
		std::string tokens[4];
		int i = 0;


		while (iss >> token)
		{
			if (i == 5)
				break;
			tokens[i++] = token;
		}

		if (i == 3 && tokens[1] == "EQUIP" && getMateriaFromGround(tokens[2]) && getCharacterByName(tokens[0]))
			getCharacterByName(tokens[0])->equip(getMateriaFromGround(tokens[2]));
		else if (i == 3 && tokens[1] == "UNEQUIP" && getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]))
			getCharacterByName(tokens[0])->unequip(std::atoi(tokens[2].c_str()));
		else if (i == 4 && tokens[1] == "USE" && getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]) && getCharacterByName(tokens[3]))
		{
			if (getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0]))->getType() == ICE)
				std::cout << "\033[36;14H\033[1;32m* shoots an ice bolt at " + tokens[3] + "\033[0m" << std::flush;
			else 
				std::cout << "\033[36;14H\033[1;32m* heals " + tokens[3] + "’s wounds *\033[0m" << std::flush;
			
			sleep(2);
		}
		else if (i == 2 && tokens[0] == "LEARN" && getMateriaFromGround(tokens[1]))
			source->learnMateria(getMateriaFromGround(tokens[1]));
		else if (i == 2 && tokens[0] == "CREATE" && getMateriaToCreateByIndex(tokens[1], source))
			continue;
			
		else if (i == 2 && tokens[0] == "CREATE" && !isDigitsOnly(tokens[1]))
		{
			if (tokens[1].size() > 12)
			{
				std::cout << "\033[36;11H\033[5;31m : Name too long\033[0m";
				term.displayError(term.errorMessage);
			}
			else
				continue;
		}
		else if (tokens[0] == "EXIT")
			break;
		else 
			term.displayError(term.errorMessage);

		
	}
	return 0;

	TEST = false;
	test_four();
	Character::cleanup();
	return 0;
}

void	print(std::string str)
{
	if (TEST)
		std::cout << str << std::endl;
}

void printB(const std::string& str)
{
	if (TEST)
		std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}

void	printF(std::string str)
{
		std::cout << str << std::endl;
}

void printFB(const std::string& str)
{
	std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}