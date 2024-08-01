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

int main()
{
	test_one();
	
	return 0;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void printB(const std::string& str)
{
    // Code d'échappement pour le texte en gras (1) et couleur verte (32)
    std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}

