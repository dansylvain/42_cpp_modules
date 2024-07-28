#include "FragTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
FragTrap::FragTrap() : ClapTrap() {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	DisplayName(" created***");};

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	DisplayName(" created***");};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	DisplayName(" created***");};

FragTrap::~FragTrap() {
	DisplayName(" destroyed***");};

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
	std::cout << "***FragTrap*** ";
	ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys() {
	print("***FragTrap*** ", this->getName(), " sends a high five, guys.");
};

void	FragTrap::DisplayName(std::string str)
{
	print("***FragTrap ", this->getName(), str);
}