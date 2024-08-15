#include "main.hpp"

int main(void)
{
	printB("****** Create ClapTraps ******");
	ClapTrap Clapster("Clapster");
	ClapTrap ZappyClap("ZappyClap");
	ClapTrap ClapMaster("ClapMaster");
	ClapTrap ClapTronix("ClapTronix");
	ClapTrap GigaClap("GigaClap");
	
	pause();
	displayClapTraps();
	
	pause();
	printB("******* test: attack *********");
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	ClapTronix.attack("Clapster");
	ZappyClap.attack("GigaClap");
	
	pause();
	printB("***** test: takeDamage *******");
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	std::cout << std::endl;
	
	pause();
	printB("***** test: beRepaired *******");
	ClapMaster.beRepaired(10);
	GigaClap.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	std::cout << std::endl;

	
	pause();
	displayClapTraps();

	pause();
	printB("****** Detroy ClapTraps ******");
	return (0);
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