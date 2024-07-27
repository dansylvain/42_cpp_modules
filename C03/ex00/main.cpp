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
	ClapTrap bobby("Bobby");
	ClapTrap lucy("Lucy");
	ClapTrap fahrid("Fahrid");
	ClapTrap clarence("Clarence");
	ClapTrap karim("Karim");
	std::cout << std::endl;
	std::cout << "ClapTraps before attacks: \n";
	displayClapTraps();
	std::cout << std::endl;
	

	fahrid.attack("Clarence");
	fahrid.attack("Clarence");
	fahrid.attack("Clarence");
	fahrid.attack("Clarence");
	fahrid.attack("Clarence");
	fahrid.attack("Clarence");
	karim.beRepaired(42);

	std::cout << std::endl;	
	std::cout << "ClapTraps after attacks." <<std::endl;
	displayClapTraps();

	return (0);
}