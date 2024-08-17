/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:39:03 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:39:03 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.hpp"

void	executeMateriaUsage(std::string tokens[])
{
	if (getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0]))->getType() == ICE)
		std::cout << "\033[36;14H\033[1;32m* shoots an ice bolt at " + tokens[3] + " *\033[0m" << std::flush;
	else 
		std::cout << "\033[36;14H\033[1;32m* heals " + tokens[3] + "’s wounds *\033[0m" << std::flush;
	
	sleep(2);
}

void	createChararacter(std::string tokens[], Terminal *term)
{
	if (tokens[1].size() > 12)
	{
		std::cout << "\033[36;11H\033[5;31m : Name too long\033[0m";
		term->displayError(term->errorMessage);
	}
	else if (Character::getCharacterCount() == 3)
	{
		std::cout << "\033[36;11H\033[5;31m : Too many characters already\033[0m";
		term->displayError(term->errorMessage);
	}
	else
	{
		Character::createNewCharacter(tokens[1]);
	}
}



int main()
{
	// vars declaration
	std::string userInput;
	Terminal term;
	MateriaSource *source;
	int i;

	// vars init
	source = new MateriaSource;
	Character::createNewCharacter("Dan");
	AMateria::addMateria(ICE);
	AMateria::addMateria(CURE);
	AMateria::addMateria(ICE);
	Character::getCharacters()[0]->equip(AMateria::getMaterias()[0]);
	source->learnMateria(AMateria::getMaterias()[0]);

	// prompt loop
	while (1)
	{
		term.execSystemCmd(term.clearCommand);
		term.displayAppState();
		term.displayString(term.contentMenu);	
			
		std::getline(std::cin, userInput);
		std::istringstream iss(userInput);
		std::string token;
		std::string tokens[4];
		i = 0;

		while (iss >> token)
		{
			if (i == 5)
				break;
			tokens[i++] = token;
		}

		if (choiceIs_EQUIP(i, tokens))
			getCharacterByName(tokens[0])->equip(getMateriaFromGround(tokens[2]));
		else if (choiceIs_UNEQUIP(i, tokens))
			getCharacterByName(tokens[0])->unequip(std::atoi(tokens[2].c_str()));
		else if (choiceIs_USE(i, tokens))
			executeMateriaUsage(tokens);
		else if (choiceIs_LEARN(i, tokens, source))
			source->learnMateria(getMateriaFromGround(tokens[1]));
		else if (choiceIs_CREATE_MATERIA(i, tokens, source))
			source->createMateria(getMateriaToCreateByIndex(tokens[1], source)->getType());
		else if (choiceIs_CREATE_CHAR(i, tokens))
			createChararacter(tokens, &term);
		else if (tokens[0] == "EXIT")
			break;
		else 
			term.displayError(term.errorMessage);
	}
	delete source;
	AMateria::cleanup();
	Character::cleanup();
	return 0;
}

bool	choiceIs_EQUIP(int i,std::string tokens[])
{
	return (i == 3 && tokens[1] == "EQUIP" && getMateriaFromGround(tokens[2])
	&& getCharacterByName(tokens[0]) && !getCharacterByName(tokens[0])->getInv()[3]);
}
bool	choiceIs_UNEQUIP(int i,std::string tokens[])
{
	return (i == 3 && tokens[1] == "UNEQUIP" && getMateriaFromCharInv(tokens[2],
	getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]));
}
bool choiceIs_USE(int i,std::string tokens[])
{
	return (i == 4 && tokens[1] == "USE" && getMateriaFromCharInv(tokens[2],
	getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]) &&
	getCharacterByName(tokens[3]) && tokens[3] != tokens[0]);
}
bool choiceIs_LEARN(int i,std::string tokens[], MateriaSource *source)
{
	return (i == 2 && tokens[0] == "LEARN" && getMateriaFromGround(tokens[1])
	&& !getMateriaToCreateByIndex("3", source));
}
bool choiceIs_CREATE_MATERIA(int i,std::string tokens[], MateriaSource *source)
{
	return (i == 2 && tokens[0] == "CREATE" && getMateriaToCreateByIndex(tokens[1],
	source));
}
bool choiceIs_CREATE_CHAR(int i,std::string tokens[])
{
	return (i == 2 && tokens[0] == "CREATE" && !isDigitsOnly(tokens[1]));
}
