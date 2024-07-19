#include "HumanB.hpp"

// constructors / destructors
HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
HumanB::~HumanB() {};

// member functions
void HumanB::attack(void)
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
};