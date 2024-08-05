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
	for (int i = 0; i < Character::characterCount; i++)
	{
		if (Character::characters[i]->getName() == name)
		{
			return (Character::characters[i]);
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
	return (character->inv[idx]);
}

AMateria *getMateriaToCreateByIndex(std::string index, MateriaSource *source)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 || idx > 4)
		return (NULL);
	return source->inv[idx];
}

AMateria *getMateriaFromGround(std::string index)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 && idx > 99)
		return (NULL);
	return AMateria::materias[idx];
}
