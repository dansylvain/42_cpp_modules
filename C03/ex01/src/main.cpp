#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}

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

void	displayClapTraps()
{
	std::cout << std::endl;
	print("*** Display: (Name, EnergyPoints, HitPoints, AttackDamage) ***");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< std::endl;
	std::cout << std::endl;	
}

void	print(std::string a) {
	std::cout << a << std::endl;
}
void	print(std::string a, std::string b) {
	std::cout << a << b << std::endl;
}
void	print(std::string a, std::string b, std::string c) {
	std::cout << a << b << c << std::endl;
}
void	print(std::string a, std::string b, std::string c, std::string d) {
	std::cout << a << b << c << d << std::endl;
}
void	print(std::string a, std::string b, int c, std::string d) {
	std::cout << a << b << c << d << std::endl;
}