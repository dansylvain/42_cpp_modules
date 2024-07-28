#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	print("### DiamondTrap created.");
	initialize();
};

DiamondTrap::DiamondTrap(const std::string& name) {
	_Name = name;
	initialize();
	print("### DiamondTrap ", _Name,  " created. ###");
};
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other) {
	initialize();
	print("### DiamondTrap ", _Name,  " created. ###");
};

DiamondTrap::~DiamondTrap() {
	print("### DiamondTrap ", _Name,  " destroyed. ###");
};

// assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	if (this == &src)
		return *this;
	ScavTrap::operator=(src);
	return *this;
};




// other methods
void whoAmI() {

};





void DiamondTrap::initialize() {
	_HitPoints = 42;
	_EnergyPoints = 42;
	_AttackDamage = 42;
	ScavTrap::DisplayName(" created.");
}