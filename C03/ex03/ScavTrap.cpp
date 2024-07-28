#include "ScavTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ScavTrap::ScavTrap() : ClapTrap() {
	initialize(" created***");}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), Name(name), 
										HitPoints(90), 
										EnergyPoints(50), 
										AttackDamage(20) {
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
void	ScavTrap::attack(const std::string& target) {
	std::cout << "***ScavTrap*** "; //* not using print coz no endl
	ClapTrap::attack(target);
}

void	ScavTrap::guardGate() const {
	print(this->getName(), " Enter Gate Keeper Mode.");
};

void	ScavTrap::DisplayName(std::string str) const {
	print("***ScavTrap ", this->getName(), str);
}
void ScavTrap::initialize(std::string str)
{
	ScavTrap::HitPoints = 90;
	ScavTrap::EnergyPoints = 50;
	ScavTrap::AttackDamage = 20;
	ScavTrap::DisplayName(str);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
// std::string ScavTrap::getName(void) const {
// 	return (Name);
// }

// int	ScavTrap::getHitPoints(void) const {
	// return (HitPoints);
// }

int	ScavTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

// int	ScavTrap::getAttackDamage(void) const {
	// return (AttackDamage);
// }