#include "FragTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
FragTrap::FragTrap() : ClapTrap() {
	DisplayName(" created***");};

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	DisplayName(" created***");};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
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

void	FragTrap::guardGate() {
	print("***FragTrap*** ", this->getName(), " Enter Gate Keeper Mode");
};

void	FragTrap::DisplayName(std::string str)
{
	print("***FragTrap ", this->getName(), str);
}