#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	print("&&& DiamondTrap created. &&&");
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), 
										FragTrap(name),
										_name(name), 
										_hitPoints(FragTrap::getHitPoints()), 
										_energyPoints(ScavTrap::getEnergyPoints()), 
										_attackDamage(FragTrap::getAttackDamage())   {
	print("&&& DiamondTrap " + _name + " created. &&&");
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)  : ClapTrap(other), ScavTrap(other), FragTrap(), 
										_name(other._name), 
										_hitPoints(other._hitPoints), 
										_energyPoints(other._energyPoints), 
										_attackDamage(other._attackDamage)  {
	print("&&& DiamondTrap " + other._name + " created. &&&");

}

DiamondTrap::~DiamondTrap() {
	print("&&& DiamondTrap " + _name + " destroyed. &&&");

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
	return (_name);
}

const int	&DiamondTrap::getHitPoints(void) const {
	return (_hitPoints);
}

const int	&DiamondTrap::getEnergyPoints(void) const {
	return (_energyPoints);
}

const int	&DiamondTrap::getAttackDamage(void) const {
	return (_attackDamage);
}

void	DiamondTrap::setHitPoints(int num) {
	this->_hitPoints += num;
	if (num == 42)
		this->_hitPoints = 0;
}

void	DiamondTrap::whoAmI()
{
	print("My name: " + this->_name);
	print("My ClapTrap Class name: " + ClapTrap::_name);
}
