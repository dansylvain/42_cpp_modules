#include "ClapTrap.hpp"

ClapTrap* ClapTrap::allClapTraps[ClapTrap::MAX_CLAPTRAPS] = { NULL };
int ClapTrap::count = 0;
/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ClapTrap::ClapTrap() : HitPoints(0), EnergyPoints(0), AttackDamage(0) {
	addClapTrap(this);
	std::cout << "ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), 
										HitPoints(10), 
										EnergyPoints(10), 
										AttackDamage(5) {
	addClapTrap(this);
	std::cout << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), 
											HitPoints(other.HitPoints), 
											EnergyPoints(other.EnergyPoints), 
											AttackDamage(other.AttackDamage) {
	addClapTrap(this);
	std::cout << Name << " created." << std::endl;
}

ClapTrap::~ClapTrap() {
	count--;
	std::cout << this->Name << " destroyed." << std::endl;
}


/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src)
	{
		this->Name = src.getName();
		this->HitPoints = src.getHitPoints();
		this->EnergyPoints = src.getEnergyPoints();
		this->AttackDamage = src.getAttackDamage();
	}
	return (*this);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
std::string ClapTrap::getName(void) const {
	return (Name);
}

int	ClapTrap::getHitPoints(void) const {
	return (HitPoints);
}

int	ClapTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

int	ClapTrap::getAttackDamage(void) const {
	return (AttackDamage);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void ClapTrap::attack(const std::string& target) {
	if (this->EnergyPoints > 0 && this->AttackDamage)
	{
		ClapTrap *tmp = findByName(target);
		if (tmp != NULL)
		{
			std::cout << (*this).getName() << " attacks " << target << " and looses 1 EnergyPoint" << std::endl;
			(*tmp).takeDamage(this->AttackDamage);
		}
		else
			std::cout  << target 
			<< " does not exist..." << std::endl;
	}
	EnergyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << (*this).getName() << " takes damage and looses " << amount << " HitPoints." << std::endl;
	this->HitPoints -= amount;
	if (this->HitPoints < 0)
		HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << (*this).getName() << " is repaired and recovers " << amount << " HitPoints." << std::endl;
	this->HitPoints += amount;
}

/**========================================================================
 *                           CLAPTRAP MANAGEMENT METHODS
 *========================================================================**/
void ClapTrap::addClapTrap(ClapTrap* clapTrap) {
	if (count < MAX_CLAPTRAPS) {
		allClapTraps[count++] = clapTrap;
	} else {
		std::cerr << "Error: Maximum number of ClapTraps reached!" << std::endl;
	}
}

ClapTrap* ClapTrap::findByName(const std::string& name) {
	for (int i = 0; i < count; ++i) {
		if (allClapTraps[i]->getName() == name) {
			return allClapTraps[i];
		}
	}
	return NULL;
}