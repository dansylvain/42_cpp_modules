#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	print("### DiamondTrap created.");
	initialize();
};

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	Name = name;
	initialize();
	print("### DiamondTrap ", Name,  " created. ###");
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	initialize();
	print("### DiamondTrap ", Name,  " created. ###");
};

DiamondTrap::~DiamondTrap() {
	print("### DiamondTrap ", Name,  " destroyed. ###");
};

// assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	if (this == &src)
		return *this;
	ScavTrap::operator=(src);
	return *this;
};

void	DiamondTrap::attack(const std::string& target) {
	std::cout << "***DiamondTrap*** ";
	ClapTrap::attack(target);
}

// other methods
void DiamondTrap::whoAmI() {

};





void DiamondTrap::initialize() {
	ClapTrap::Name += "_clap_name";
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	ScavTrap::DisplayName(" created.");
}