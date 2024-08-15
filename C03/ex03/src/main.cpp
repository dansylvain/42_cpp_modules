#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}
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
	pause();
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
	pause();

	print("***********************************");
	print("****** Copy constructor test ******");
	print("***********************************");
	ClapTrap ClapCopy(ClappyClappo);
	ScavTrap CopyTrap(ScavTronix);
	FragTrap FragCopy(FraggyBoy);
	DiamondTrap DiamondCopy(PearlTrap);

	ClapTrap::displayClapTraps();
	pause();
	
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

	pause();

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
	pause();

	print("******************************");
	print("**** special Traps tests *****");
	ScavBuddy.guardGate();
	FraggyBoy.highFivesGuys();
	PearlTrap.whoAmI();
	print("");
	pause();
	
	print("****************************************");
	print("****** Diamond values access test ******");
	print("****************************************");
		print("ClapTrap values of " + PearlTrap.getName());
	print(PearlTrap.ClapTrap::getName());
	print(PearlTrap.ClapTrap::getHitPoints());
	print(PearlTrap.ClapTrap::getEnergyPoints());
	print(PearlTrap.ClapTrap::getAttackDamage());
	pause();

	print("");
	print("ScavTrap values of " + PearlTrap.getName());
	print(PearlTrap.ScavTrap::getName());
	print(PearlTrap.ScavTrap::getHitPoints());
	print(PearlTrap.ScavTrap::getEnergyPoints());
	print(PearlTrap.ScavTrap::getAttackDamage());
	pause();

	print("");
	print("FragTrap values of " + PearlTrap.getName());
	print(PearlTrap.FragTrap::getName());
	print(PearlTrap.FragTrap::getHitPoints());
	print(PearlTrap.FragTrap::getEnergyPoints());
	print(PearlTrap.FragTrap::getAttackDamage());
	pause();

	print("");
	print("DiamondTrap values of " + PearlTrap.getName());
	print(PearlTrap.getName());
	print(PearlTrap.getHitPoints());
	print(PearlTrap.getEnergyPoints());
	print(PearlTrap.getAttackDamage());
	print("");

	ClapTrap::displayClapTraps();



	pause();

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