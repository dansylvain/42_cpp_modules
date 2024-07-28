#include "ScavTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ScavTrap::ScavTrap() : ClapTrap() {
	DisplayName(" created***");};

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	DisplayName(" created***");};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	DisplayName(" created***");};

ScavTrap::~ScavTrap() {
	DisplayName(" destroyed***");};

/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void ScavTrap::attack(const std::string& target) {
	std::cout << "***ScrapTrap*** ";
	ClapTrap::attack(target);
}

void ScavTrap::guardGate() {
	print("***ScrapTrap*** ", this->getName(), " Enter Gate Keeper Mode");
};
