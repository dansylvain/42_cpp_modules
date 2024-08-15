#include "main.hpp"

int main(void)
{
	print("****** Create ClapTraps and ScavTraps ******");
	ScavTrap Scavster("Scavster");
	ClapTrap ZappyClap("ZappyClap");
	ScavTrap ScavMaster("ScavMaster");
	ScavTrap ScavTronix("ScavTronix");
	ScavTrap GigaScav("GigaScav");
	pause();
	displayClapTraps();
	
	print("******* test: attack *********");
	Scavster.attack("NonExistingClapTrap");
	Scavster.attack("");
	ZappyClap.attack("ScavTronix");
	Scavster.attack("ScavTronix");
	Scavster.attack("ScavTronix");
	Scavster.attack("ScavTronix");
	Scavster.attack("ScavTronix");
	Scavster.attack("ScavTronix");
	Scavster.attack("ScavTronix");
	ScavTronix.attack("Scavster");
	ZappyClap.attack("GigaScav");
	print("");
	pause();
	print("***** test: takeDamage *******");
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	print("");	
	pause();
	print("***** test: beRepaired *******");
	ScavMaster.beRepaired(10);
	GigaScav.beRepaired(2);
	Scavster.beRepaired(2);
	Scavster.beRepaired(2);
	print("");
	pause();
	print("****** special Traps tests ******");
	ScavTrap Scavilax("Scavilax");
	Scavilax.guardGate();
	print("");
	pause();
	displayClapTraps();
	
	print("****** Detroy ClapTraps ******");
	
	return (0);
}

