#include "HumanA.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{}

HumanA::~HumanA()
{}

/**========================================================================
 *                           MEMBER FUNCTIONS
 *========================================================================**/
void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
};