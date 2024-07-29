#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {

}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(), ScavTrap(), FragTrap() {
(void)name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)  : ClapTrap(), ScavTrap(), FragTrap() {
(void)other;
}

DiamondTrap::~DiamondTrap() {

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
(void)src;
return (*this);
}
