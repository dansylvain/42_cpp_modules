#include "ClapTrap.hpp"

/**========================================================================
 *                           STATIC VARS INITIALISATION
 *========================================================================**/
ClapTrap* 	ClapTrap::allClapTraps[ClapTrap::MAX_CLAPTRAPS] = { NULL };
int 		ClapTrap::count = 0;

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ClapTrap::ClapTrap() : HitPoints(0), EnergyPoints(0), AttackDamage(0) {
	addClapTrap(this);
	print("--- ClapTrap created. ---");
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), 
										HitPoints(10), 
										EnergyPoints(10), 
										AttackDamage(0) {
	addClapTrap(this);
	print("--- ClapTrap ", name, " created. ---");
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), 
											HitPoints(other.HitPoints), 
											EnergyPoints(other.EnergyPoints), 
											AttackDamage(other.AttackDamage) {
	addClapTrap(this);
	print("--- ClapTrap ", Name, " created. ---");
}

ClapTrap::~ClapTrap() {
	count--;
	print("--- ClapTrap ", Name, " destroyed. ---");
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
const std::string &ClapTrap::getName(void) const {
	return (Name);
}

const int	&ClapTrap::getHitPoints(void) const {
	return (HitPoints);
}

const int	&ClapTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

const int	&ClapTrap::getAttackDamage(void) const {
	return (AttackDamage);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void ClapTrap::attack(const std::string& target) {
	// std::cout << "AttackDamage VALUE: " << AttackDamage << std::endl;
	attack(target, AttackDamage);
}

void ClapTrap::attack(const std::string& target, int AD) {
	if (this->HitPoints == 0)
	{
		print(this->Name, " is dead and can't attack.");
		return ;
	}
	int num;
	if (findByName(target))
		num = (*findByName(target)).getHitPoints();

	// std::cout <<"LOOOOK HHHHEEEEEEERRRRRRRREEEEEEEEEEE :"<< num <<std::endl;
	if (findByName(target) != NULL && findByName(target)->getHitPoints() == 0)
	{
		print(this->Name, " attacks ", target, ", but it is already dead.");
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		print(this->getName(), " has no energy left and can't attack.");
		return ;
	}	
	if (findByName(target) != NULL)
	{
		print(this->getName(), " attacks ", target, 
		" and looses 1 EnergyPoint.");
		(*findByName(target)).takeDamage(AD, num);
	}
	else
		print(target, " does not exist...");
	EnergyPoints -= 1;
}


void ClapTrap::takeDamage(unsigned int amount) {
	
	if (this->getHitPoints() == 0)
	{
		print(this->Name, " is already dead.");
		return ;
	}
	this->HitPoints -= amount;
	if (this->getHitPoints() <= 0)
	{
		print(this->getName(), " dies.");
		HitPoints = 0;
		return ;
	}
	print(this->getName(), " takes damage and looses ",
	 amount, " HitPoints.");
}

void ClapTrap::takeDamage(unsigned int amount, int HP) {
	std::cout << "******************************************HP LEFT:" << this->getHitPoints()<< std::endl;
	if (HP == 0)
	{
		print(this->Name, " is already dead.");
		return ;
	}
	this->HitPoints -= amount;
	if (this->HitPoints <= 0)
	{
		print(this->getName(), " dies.");
		HitPoints = 0;
		return ;
	}
	print(this->getName(), " takes damage and looses ",
	 amount, " HitPoints.");
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->HitPoints == 0)
	{
		print(this->Name, " is dead and can't do anything.");
		return ;
	}
	if ((*this).getEnergyPoints() > 0)
	{
		print(this->getName(), " repaires itself, recovers ",
		 amount, " HitPoints, and looses 1 EnergyPoint.");
		this->HitPoints += amount;
		this->EnergyPoints--;
	}
	else
		print(this->getName(), " has no energy left and can't be repaired.");
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
			// std::cout << "TRAP FOUND: "+ allClapTraps[i]->Name + "HP: " << allClapTraps[i]->getHitPoints() << std::endl;
			return allClapTraps[i];
		}
	}
	return NULL;
}

void	ClapTrap::displayClapTraps()
{
	print("");
	print("*** Display: (Name, EnergyPoints, HitPoints, AttackDamage) ***");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< "." << std::endl;
	print("");	
}

/**========================================================================
 *                           UTILS METHODS
 *========================================================================**/


