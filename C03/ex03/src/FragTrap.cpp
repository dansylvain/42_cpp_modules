#include "FragTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
FragTrap::FragTrap() : ClapTrap() {
	initialize(" created ###");}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name), _name(name), 
										_hitPoints(100), 
										_energyPoints(100), 
										_attackDamage(30)  {
	initialize(" created ###");
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other), _name(other._name), 
										_hitPoints(other._hitPoints), 
										_energyPoints(other._energyPoints), 
										_attackDamage(other._attackDamage)  {
	initialize(" created ###");}

FragTrap::~FragTrap() {
	DisplayName(" destroyed ###");};

/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
FragTrap& FragTrap::operator=(const FragTrap& src) {
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void	FragTrap::attack(const std::string& target) {
	std::cout << "### FragTrap ### ";
	ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys() const {
	print(this->getName() + " sends a high five, guys.");
}

void	FragTrap::DisplayName(std::string str) const {
	print("### FragTrap " + this->getName() + str);
}

void FragTrap::initialize(std::string str) {
	print("### FragTrap " + _name + str);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
const std::string &FragTrap::getName(void) const {
	return (_name);
}

const int	&FragTrap::getHitPoints(void) const {
	return (_hitPoints);
}

const int	&FragTrap::getEnergyPoints(void) const {
	return (_energyPoints);
}

const int	&FragTrap::getAttackDamage(void) const {
	return (_attackDamage);
}

void	FragTrap::setHitPoints(int num) {
	this->_hitPoints += num;
	if (num == 42)
		this->_hitPoints = 0;
}