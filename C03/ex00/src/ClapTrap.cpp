#include "ClapTrap.hpp"

ClapTrap* ClapTrap::allClapTraps[ClapTrap::MAX_CLAPTRAPS] = { NULL };
int ClapTrap::count = 0;
/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ClapTrap::ClapTrap() : _hitPoints(0), _energyPoints(0), _attackDamage(0) {
	addClapTrap(this);
	std::cout << "ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), 
										_hitPoints(10), 
										_energyPoints(10), 
										_attackDamage(6) {
	addClapTrap(this);
	std::cout << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), 
											_hitPoints(other._hitPoints), 
											_energyPoints(other._energyPoints), 
											_attackDamage(other._attackDamage) {
	addClapTrap(this);
	std::cout << _name << " created." << std::endl;
}

ClapTrap::~ClapTrap() {
	count--;
	std::cout << this->_name << " destroyed." << std::endl;
}


/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
std::string ClapTrap::getName(void) const {
	return (_name);
}

int	ClapTrap::getHitPoints(void) const {
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const {
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const {
	return (_attackDamage);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is dead and can't attack." << std::endl;
		return ;
	}
	ClapTrap *tmp = findByName(target);
	if (tmp != NULL && tmp->getHitPoints() == 0)
	{
		std::cout << this->_name << " attacks " << target << ", but it is already dead." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy left and can't attack." << std::endl;
		return ;
	}	
	if (tmp != NULL)
	{
		std::cout << this->getName() << " attacks " << target << " and looses 1 EnergyPoint" << std::endl;
		(*tmp).takeDamage(this->_attackDamage);
	}
	else
		std::cout  << target 
		<< " does not exist..." << std::endl;
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is already dead." << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << this->getName() << " looses " << amount + this->getHitPoints() << " _hitPoints, and dies." << std::endl;
		_hitPoints = 0;
		return ;
	}
	std::cout << this->getName() << " takes damage and looses " << amount << " _hitPoints." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is dead and can't do anything." << std::endl;
		return ;
	}
	if ((*this).getEnergyPoints() > 0)
	{
		std::cout << this->getName() << " repaires itself, recovers " << amount << " _hitPoints, and looses 1 EnergyPoint." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << this->getName() << " has no energy left and can't be repaired." << std::endl;
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