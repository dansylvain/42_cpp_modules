#include "ClapTrap.hpp"

void	displayClapTraps()
{
	std::cout << std::endl;	
	std::cout << "*** Display: (Name, EnergyPoints, HitPoints, AttackDamage) ***" << std::endl;
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

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

int main(void)
{
	std::cout << "****** Create ClapTraps ******" << std::endl;
	ClapTrap Clapster("Clapster");
	ClapTrap ZappyClap("ZappyClap");
	ClapTrap ClapMaster("ClapMaster");
	ClapTrap ClapTronix("ClapTronix");
	ClapTrap GigaClap("GigaClap");
	
	
	displayClapTraps();
	pause();
	std::cout << "******* test: attack *********" << std::endl;
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	ClapTronix.attack("Clapster");
	std::cout << std::endl;
	ZappyClap.attack("GigaClap");
	pause();
	
	std::cout << "***** test: takeDamage *******" << std::endl;
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	ClapMaster.takeDamage(3);
	std::cout << std::endl;
	pause();
	
	std::cout << "***** test: beRepaired *******" << std::endl;
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

	std::cout << "****** Detroy ClapTraps ******" << std::endl;
	return (0);
}