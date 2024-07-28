#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	displayClapTraps()
{
	print("");
	print("*** Display: (Name, EnergyPoints, HitPoints, AttackDamage) ***");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << i << " - " << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< "." << std::endl;
	print("");	
}

int main(void)
{
	print("****** Create ClapTraps ******");
	ClapTrap	ClappyClappo("ClappyClappo");
	ScavTrap	Clapster("Clapster");
	ClapTrap	ZappyClap("ZappyClap");
	ScavTrap	ScavMaster("ScavMaster");
	ScavTrap	ScavTronix("ScavTronix");
	ScavTrap	GigaScav("GigaScav");
	ScavTrap	ScavBuddy("ScavBuddy");
	FragTrap	FraggyBoy("FraggyBoy");
	DiamondTrap	PreciousTrap("PreciousTrap");
	
	displayClapTraps();
	
	print("******* test: attack *********");
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
	
	print("***** test: takeDamage *******");
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	print("");

	print("***** test: beRepaired *******");
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

	print("****** special Traps tests ******");
	ScavBuddy.guardGate();
	FraggyBoy.highFivesGuys();
	print("");
	
	displayClapTraps();




	print("****** Detroy Claptraps ******");
	return (0);
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