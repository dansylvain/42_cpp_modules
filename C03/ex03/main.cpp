#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	print("******************************");
	print("****** Create ClapTraps ******");
	print("******************************");
	ClapTrap ClappyClappo("ClappyClappo");
	ScavTrap Clapster("Clapster");
	ClapTrap ZappyClap("ZappyClap");
	ScavTrap ScavMaster("ScavMaster");
	ScavTrap ScavTronix("ScavTronix");
	ScavTrap GigaScav("GigaScav");
	ScavTrap ScavBuddy("ScavBuddy");
	FragTrap FraggyBoy("FraggyBoy");
	DiamondTrap PearlTrap("PearlTrap");
	
	ClapTrap::displayClapTraps();
	


	print("******************************");
	print("******* test: attack *********");
	print("******************************");
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

	print("***********************************");
	print("****** Copy constructor test ******");
	print("***********************************");
	ClapTrap ClapCopy(ClappyClappo);
	ScavTrap CopyTrap(ScavTronix);
	FragTrap FragCopy(FraggyBoy);
	DiamondTrap DiamondCopy(PearlTrap);

	ClapTrap::displayClapTraps();
	
	print("******************************");
	print("***** test: takeDamage *******");
	print("******************************");
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	print("");


	print("******************************");
	print("***** test: beRepaired *******");
	print("******************************");
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

	print("******************************");
	print("**** special Traps tests *****");
	ScavBuddy.guardGate();
	FraggyBoy.highFivesGuys();
	PearlTrap.whoAmI();
	print("");
	
	print("****************************************");
	print("****** Diamond values access test ******");
	print("****************************************");
		print("ClapTrap values of " + PearlTrap.getName());
	print(PearlTrap.ClapTrap::getName());
	print(PearlTrap.ClapTrap::getHitPoints());
	print(PearlTrap.ClapTrap::getEnergyPoints());
	print(PearlTrap.ClapTrap::getAttackDamage());

	print("");
	print("ScavTrap values of " + PearlTrap.getName());
	print(PearlTrap.ScavTrap::getName());
	print(PearlTrap.ScavTrap::getHitPoints());
	print(PearlTrap.ScavTrap::getEnergyPoints());
	print(PearlTrap.ScavTrap::getAttackDamage());

	print("");
	print("FragTrap values of " + PearlTrap.getName());
	print(PearlTrap.FragTrap::getName());
	print(PearlTrap.FragTrap::getHitPoints());
	print(PearlTrap.FragTrap::getEnergyPoints());
	print(PearlTrap.FragTrap::getAttackDamage());

	print("");
	print("DiamondTrap values of " + PearlTrap.getName());
	print(PearlTrap.getName());
	print(PearlTrap.getHitPoints());
	print(PearlTrap.getEnergyPoints());
	print(PearlTrap.getAttackDamage());
	print("");

	ClapTrap::displayClapTraps();




	print("******************************");
	print("****** Detroy Claptraps ******");
	print("******************************");
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
void	print(int n) {
	std::cout << n << std::endl;
}