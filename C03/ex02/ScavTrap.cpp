#include "ScavTrap.hpp"



void ScavTrap::guardGate() {
std::cout << this->getName() << " Enter Gate Keeper Mode" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}