/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:37:53 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:37:53 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "MateriaSource.hpp"
#include "Terminal.hpp"	
#include <sstream>
#include "unistd.h"
#include "Character.hpp"

bool isDigitsOnly(const std::string& str);
Character *getCharacterByName(std::string name);
AMateria *getMateriaFromCharInv(std::string index, Character *character);
AMateria *getMateriaToCreateByIndex(std::string index, MateriaSource *source);
AMateria *getMateriaFromGround(std::string index);


bool	choiceIs_EQUIP(int i,std::string tokens[]);
bool	choiceIs_UNEQUIP(int i,std::string tokens[]);
bool choiceIs_USE(int i,std::string tokens[]);
bool choiceIs_LEARN(int i,std::string tokens[], MateriaSource *source);
bool choiceIs_CREATE_MATERIA(int i,std::string tokens[], MateriaSource *source);
bool choiceIs_CREATE_CHAR(int i,std::string tokens[]);