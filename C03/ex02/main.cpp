#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

int main(void)
{
	std::cout << "****** Create Clapsters ******" << std::endl;
	ScavTrap Clapster("Clapster");
	ScavTrap ZappyClap("ZappyClap");
	ScavTrap ClapMaster("ClapMaster");
	ScavTrap ClapTronix("ClapTronix");
	ScavTrap GigaClap("GigaClap");
	
	
	displayClapTraps();
	
	std::cout << "******* test: attack *********" << std::endl;
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	ClapTronix.attack("Clapster");
	std::cout << std::endl;
	ZappyClap.attack("GigaClap");
	
	std::cout << "***** test: takeDamage *******" << std::endl;
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	std::cout << std::endl;
	
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

	
	displayClapTraps();


	ScavTrap loulou("Loulou");
	loulou.guardGate();


	std::cout << "****** Detroy Clapsters ******" << std::endl;
	return (0);
}