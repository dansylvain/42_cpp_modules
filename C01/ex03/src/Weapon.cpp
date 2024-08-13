#include "Weapon.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Weapon::Weapon()
{};
Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon(){};

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
const std::string &Weapon::getType(void) const
{
	const std::string &typeREF = this->type;
	return (typeREF);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}