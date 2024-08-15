#include "ClapTrap.hpp"

/**========================================================================
 *                           STATIC VARS INITIALISATION
 *========================================================================**/
ClapTrap* 	ClapTrap::allClapTraps[ClapTrap::MAX_CLAPTRAPS] = { NULL };
int 		ClapTrap::count = 0;

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ClapTrap::ClapTrap() : _hitPoints(0), _energyPoints(0), _attackDamage(0) {
	addClapTrap(this);
	print("ClapTrap created.");
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), 
										_hitPoints(10), 
										_energyPoints(10), 
										_attackDamage(0) {
	addClapTrap(this);
	print("ClapTrap " + name + " created.");
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), 
											_hitPoints(other._hitPoints), 
											_energyPoints(other._energyPoints), 
											_attackDamage(other._attackDamage) {
	addClapTrap(this);
	print("ClapTrap " + _name + " created.");
}

ClapTrap::~ClapTrap() {
	count--;
	print("ClapTrap " + _name + " destroyed.");
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
		print(this->_name + " is dead and can't attack.");
		return ;
	}
	ClapTrap *tmp = findByName(target);
	if (tmp != NULL && tmp->getHitPoints() == 0)
	{
		print(this->_name + " attacks " + target + ", but it is already dead.");
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		print(this->getName() + " has no energy left and can't attack.");
		return ;
	}	
	if (tmp != NULL)
	{
		print(this->getName() + " attacks " + target + 
		" and looses 1 EnergyPoint.");
		(*tmp).takeDamage(this->_attackDamage);
	}
	else
		print(target + " does not exist...");
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		print(this->_name + " is already dead.");
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		print(this->getName(), " looses ", 
		amount + this->getHitPoints(), " _hitPoints, and dies.");
		_hitPoints = 0;
		return ;
	}
	print(this->getName(), " takes damage and looses ",
	 amount, " _hitPoints.");
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		print(this->_name + " is dead and can't do anything.");
		return ;
	}
	if ((*this).getEnergyPoints() > 0)
	{
		print(this->getName(), " repaires itself, recovers ",
		 amount, " _hitPoints, and looses 1 EnergyPoint.");
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		print(this->getName() + " has no energy left and can't be repaired.");
}

/**========================================================================
 *                           CLAPTRAP MANAGEMENT METHODS
 *========================================================================**/
void ClapTrap::addClapTrap(ClapTrap* clapTrap) {
	if (count < MAX_CLAPTRAPS) {
		allClapTraps[count++] = clapTrap;
	} else {
		print("Error: Maximum number of ClapTraps reached!");
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

/**========================================================================
 *                           UTILS METHODS
 *========================================================================**/


