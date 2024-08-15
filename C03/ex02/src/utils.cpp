#include "main.hpp"
#include <iostream>

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void	print(std::string a, std::string b, int c, std::string d)
{
	std::cout << a << b << c << d << std::endl;
}

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

void	displayClapTraps()
{
	std::cout << std::endl;	
	printB("*** Display: (_name, _energyPoints, _hitPoints, _attackDamage) ***");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< std::endl;
	std::cout << std::endl;	
}


void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}