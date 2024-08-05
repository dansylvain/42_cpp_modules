#ifndef MAIN_H
#define MAIN_H

#define ICE "ice"
#define CURE "cure"
#define GROUND "ground"
#define MATERIASOURCE "materiaSource"

typedef enum
{
	e_ICE,
	e_CURE,
} eType;

typedef enum
{
	e_GROUND,
	e_MATERIASOURCE
} eLoc;

#define MAXMATERIA 100
#include <iostream>

void	print(std::string str);
void	printB(const std::string& str);
void	print(std::string str);
void	printB(const std::string& str);
void	printF(std::string str);
void	printFB(const std::string& str);
extern bool TEST;

#endif