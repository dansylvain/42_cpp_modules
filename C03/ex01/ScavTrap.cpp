#include "ScavTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ScavTrap::ScavTrap() : ClapTrap() {
	initialize(" created***");}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	initialize(" created***");}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	initialize(" created***");}

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

void	ScavTrap::DisplayName(std::string str)
{
	print("***ScavTrap ", this->getName(), str);
}
void ScavTrap::initialize(std::string str)
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	DisplayName(str);
}