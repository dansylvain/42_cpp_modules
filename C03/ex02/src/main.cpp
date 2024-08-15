#include "main.hpp"

int main(void)
{
	printB("****** Create ClapTraps ******");
	ClapTrap ClappyClappo("ClappyClappo");
	ScavTrap Clapster("Clapster");
	ClapTrap ZappyClap("ZappyClap");
	ScavTrap ScavMaster("ScavMaster");
	ScavTrap ScavTronix("ScavTronix");
	ScavTrap GigaScav("GigaScav");
	ScavTrap ScavBuddy("ScavBuddy");
	FragTrap FraggyBoy("FraggyBoy");
	pause();
	displayClapTraps();
	
	pause();
	printB("******* test: attack *********");
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	ScavTronix.attack("Clapster");
	print("");
	ZappyClap.attack("GigaScav");
	pause();
	
	printB("***** test: takeDamage *******");
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	print("");
	pause();

	printB("***** test: beRepaired *******");
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	print("");
	pause();

	printB("****** special Traps tests ******");
	ScavBuddy.guardGate();
	FraggyBoy.highFivesGuys();
	print("");
	
	pause();
	displayClapTraps();




	pause();
	printB("****** Detroy Claptraps ******");
	return (0);
}
