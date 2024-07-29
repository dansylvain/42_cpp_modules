#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	print("&&& DiamondTrap created. &&&");
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), 
										FragTrap(name),
										Name(name), 
										HitPoints(FragTrap::getHitPoints()), 
										EnergyPoints(ScavTrap::getEnergyPoints()), 
										AttackDamage(FragTrap::getAttackDamage())   {
	print("&&& DiamondTrap ", Name, " created. &&&");
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)  : ClapTrap(other), ScavTrap(other), FragTrap(), 
										Name(other.Name), 
										HitPoints(other.HitPoints), 
										EnergyPoints(other.EnergyPoints), 
										AttackDamage(other.AttackDamage)  {
	print("&&& DiamondTrap ", other.Name, " created. &&&");

}

DiamondTrap::~DiamondTrap() {
	print("&&& DiamondTrap ", Name, " destroyed. &&&");

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
(void)src;
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	return *this;
return (*this);
}


/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
const std::string &DiamondTrap::getName(void) const {
	return (Name);
}

const int	&DiamondTrap::getHitPoints(void) const {
	return (HitPoints);
}

const int	&DiamondTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

const int	&DiamondTrap::getAttackDamage(void) const {
	return (AttackDamage);
}

void	DiamondTrap::setHitPoints(int num) {
	// std::cout << "HitPoints INSIDE SETHITPOINTS FUNC" << this->HitPoints <<std::endl;
	this->HitPoints += num;
}

void	DiamondTrap::whoAmI()
{
	print("My name: " + this->Name);
	print("My ClapTrap Class name: " + ClapTrap::Name);
}
