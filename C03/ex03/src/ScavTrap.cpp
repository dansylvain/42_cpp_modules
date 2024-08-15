#include "ScavTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ScavTrap::ScavTrap() : ClapTrap() {
	initialize(" created ***");}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _name(name), 
										_hitPoints(100), 
										_energyPoints(50), 
										_attackDamage(20)  {
	initialize(" created ***");
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _name(other._name), 
										_hitPoints(other._hitPoints), 
										_energyPoints(other._energyPoints), 
										_attackDamage(other._attackDamage) {
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
	ClapTrap::attack(target, _attackDamage);
}

void	ScavTrap::guardGate() const {
	print(this->getName() + " Enter Gate Keeper Mode.");
};

void	ScavTrap::DisplayName(std::string str) const {
	print("***ScavTrap " + this->getName() + str);
}
void ScavTrap::initialize(std::string str)
{
	print("*** ScavTrap " + _name + str);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
const std::string &ScavTrap::getName(void) const {
	return (_name);
}

const int	&ScavTrap::getHitPoints(void) const {
	return (_hitPoints);
}

const int	&ScavTrap::getEnergyPoints(void) const {
	return (_energyPoints);
}

const int	&ScavTrap::getAttackDamage(void) const {
	return (_attackDamage);
}

void	ScavTrap::setHitPoints(int num) {
	this->_hitPoints += num;
	if (num == 42)
		this->_hitPoints = 0;
}
