#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Terminal.hpp"	
#include <sstream>
#include <string>

void	print(std::string str);
void	printB(const std::string& str);
void printFB(const std::string& str);

void	printF(std::string str);
void	test_three();

bool TEST;


bool isDigitsOnly(const std::string& str) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!std::isdigit(static_cast<unsigned char>(*it))) {
			return false;
		}
	}
	return true;
}

Character *getCharacterByName(std::string name)
{
	for (int i = 0; i < Character::getCharacterCount(); i++)
	{
		if (Character::getCharacters()[i]->getName() == name)
		{
			return (Character::getCharacters()[i]);
		}
	}
	return (NULL);
}

AMateria *getMateriaFromCharInv(std::string index, Character *character)
{
	if (!isDigitsOnly(index) || index.empty() || !character)
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 || idx > 3)
		return (NULL);
	return (character->getInv()[idx]);
}

AMateria *getMateriaToCreateByIndex(std::string index, MateriaSource *source)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 || idx > 4)
		return (NULL);
	return source->getInv()[idx];
}

AMateria *getMateriaFromGround(std::string index)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 || idx > 99)
		return (NULL);
	return AMateria::getMaterias()[idx];
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