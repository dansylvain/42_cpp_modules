#include "HumanB.hpp"

// constructors / destructors
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {};

// member functions
void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon* weapon)
{
	if (weapon)
		this->weapon = weapon;
}

