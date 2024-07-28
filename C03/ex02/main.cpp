#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	displayClapTraps()
{
	print("");
	print("*** Display: (Name, EnergyPoints, HitPoints, AttackDamage) ***");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< std::endl;
	print("");	
}

int main(void)
{
	print("****** Create ClapTraps ******");
	ScavTrap Clapster("Clapster");
	ScavTrap ZappyClap("ZappyClap");
	ScavTrap ClapMaster("ClapMaster");
	ScavTrap ClapTronix("ClapTronix");
	ScavTrap GigaClap("GigaClap");
	
	
	displayClapTraps();
	
	print("******* test: attack *********");
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	Clapster.attack("ClapTronix");
	ClapTronix.attack("Clapster");
	print("");
	ZappyClap.attack("GigaClap");
	
	print("***** test: takeDamage *******");
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	ClapMaster.takeDamage(22);
	print("");

	print("***** test: beRepaired *******");
	ClapMaster.beRepaired(10);
	GigaClap.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	Clapster.beRepaired(2);
	print("");

	print("****** special Traps tests ******");
	ScavTrap loulou("Loulou");
	FragTrap FraggyBoy("FraggyBoy");
	loulou.guardGate();
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