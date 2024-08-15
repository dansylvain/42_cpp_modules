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

