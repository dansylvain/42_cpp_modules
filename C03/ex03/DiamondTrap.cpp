#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {

}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
(void)name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)  : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	
}

DiamondTrap::~DiamondTrap() {

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
