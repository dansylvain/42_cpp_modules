#include "ScavTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ScavTrap::ScavTrap() : ClapTrap() {
	initialize(" created ***");}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), Name(name), 
										HitPoints(100), 
										EnergyPoints(50), 
										AttackDamage(20)  {
	initialize(" created ***");
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	initialize(" created ***");} 

ScavTrap::~ScavTrap() {
	DisplayName(" destroyed ***");};
	
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
	ClapTrap::attack(target, AttackDamage);
}

void	ScavTrap::guardGate() const {
	print(this->getName(), " Enter Gate Keeper Mode.");
};

void	ScavTrap::DisplayName(std::string str) const {
	print("***ScavTrap ", this->getName(), str);
}
void ScavTrap::initialize(std::string str)
{
	print("*** ", Name, str);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
const std::string &ScavTrap::getName(void) const {
	return (Name);
}

const int	&ScavTrap::getHitPoints(void) const {
	return (HitPoints);
}

const int	&ScavTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

const int	&ScavTrap::getAttackDamage(void) const {
	return (AttackDamage);
}

