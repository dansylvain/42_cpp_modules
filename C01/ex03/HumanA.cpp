#include "HumanA.hpp"

// constructors / destructors
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
HumanA::~HumanA() {};

// member functions
void HumanA::attack(void)
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
};