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
	DiamondTrap PearlTrap("PearlTrap");
	pause();
	ClapTrap::displayClapTraps();
	

	pause();
	printB("******* test: attack *********");
	ClappyClappo.attack("ZappyClap");
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


	pause();
	printB("****** Copy constructor test ******");
	ClapTrap ClapCopy(ClappyClappo);
	ScavTrap CopyTrap(ScavTronix);
	FragTrap FragCopy(FraggyBoy);
	DiamondTrap DiamondCopy(PearlTrap);

	pause();
	ClapTrap::displayClapTraps();
	
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
	printB("**** special Traps tests *****");
	ScavBuddy.guardGate();
	FraggyBoy.highFivesGuys();
	PearlTrap.whoAmI();
	print("");
	
	pause();
	printB("****** Diamond values access test ******");
	print("ClapTrap values of " + PearlTrap.getName());
	print(PearlTrap.ClapTrap::getName());
	print(PearlTrap.ClapTrap::getHitPoints());
	print(PearlTrap.ClapTrap::getEnergyPoints());
	print(PearlTrap.ClapTrap::getAttackDamage());

	print("");
	pause();
	printB("ScavTrap values of " + PearlTrap.getName());
	print(PearlTrap.ScavTrap::getName());
	print(PearlTrap.ScavTrap::getHitPoints());
	print(PearlTrap.ScavTrap::getEnergyPoints());
	print(PearlTrap.ScavTrap::getAttackDamage());

	print("");
	pause();
	printB("FragTrap values of " + PearlTrap.getName());
	print(PearlTrap.FragTrap::getName());
	print(PearlTrap.FragTrap::getHitPoints());
	print(PearlTrap.FragTrap::getEnergyPoints());
	print(PearlTrap.FragTrap::getAttackDamage());

	print("");
	pause();
	printB("DiamondTrap values of " + PearlTrap.getName());
	print(PearlTrap.getName());
	print(PearlTrap.getHitPoints());
	print(PearlTrap.getEnergyPoints());
	print(PearlTrap.getAttackDamage());
	print("");

	pause();
	ClapTrap::displayClapTraps();



	pause();
	printB("****** Detroy Claptraps ******");

	return (0);
}

