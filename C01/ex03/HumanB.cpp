#include "HumanB.hpp"

// constructors / destructors
HumanB::HumanB(std::string name) : name(name) {}
HumanB::~HumanB() {};

// member functions
void HumanB::attack(void)
{
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

