#include "Weapon.hpp"

// constructors
Weapon::Weapon(){};
Weapon::Weapon(std::string type){this->type = type;};

// destructor
Weapon::~Weapon(){};

// getters and setters
const std::string &Weapon::getType(void) const
{
	const std::string &typeREF = this->type;
	return (typeREF);
}

void Weapon::setType(std::string type){this->type = type;};