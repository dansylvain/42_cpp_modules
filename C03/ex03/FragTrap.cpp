#include "FragTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
FragTrap::FragTrap() : ClapTrap() {
	initialize(" created ###");}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name), Name(name), 
										HitPoints(100), 
										EnergyPoints(100), 
										AttackDamage(30)  {
	initialize(" created ###");
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other), Name(other.Name), 
										HitPoints(other.HitPoints), 
										EnergyPoints(other.EnergyPoints), 
										AttackDamage(other.AttackDamage)  {
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
	print(this->getName(), " sends a high five, guys.");
}

void	FragTrap::DisplayName(std::string str) const {
	print("### FragTrap ", this->getName(), str);
}

void FragTrap::initialize(std::string str) {
	print("### FragTrap ", Name, str);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
const std::string &FragTrap::getName(void) const {
	return (Name);
}

const int	&FragTrap::getHitPoints(void) const {
	return (HitPoints);
}

const int	&FragTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

const int	&FragTrap::getAttackDamage(void) const {
	return (AttackDamage);
}

void	FragTrap::setHitPoints(int num) {
	// std::cout << "HitPoints INSIDE SETHITPOINTS FUNC" << this->HitPoints <<std::endl;
	this->HitPoints += num;
}