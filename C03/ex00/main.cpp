#include "ClapTrap.hpp"

void	displayClapTraps()
{
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< std::endl;
	
}

int main(void)
{
	ClapTrap Clapster("Clapster");
	ClapTrap ZappyClap("ZappyClap");
	ClapTrap ClapMaster("ClapMaster");
	ClapTrap ClapTronix("ClapTronix");
	ClapTrap GigaClap("GigaClap");
	
	std::cout << std::endl;
	std::cout << "ClapTraps display before attacks: " << std::endl;
	displayClapTraps();
	std::cout << std::endl;
	
	std::cout << "test: attack" << std::endl;
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	ClapTronix.attack("Clapster");
	

	
	std::cout << std::endl;	
	std::cout << "ClapTraps display after attacks:" <<std::endl;
	displayClapTraps();
	std::cout << std::endl;	

	return (0);
}